#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

static const char *get_exec_dir(void) {
    static char dir[PATH_MAX];
    char exe[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", exe, sizeof(exe) - 1);
    if (len <= 0) {
        return NULL;
    }
    exe[len] = '\0';
    char *slash = strrchr(exe, '/');
    if (!slash) {
        return NULL;
    }
    *slash = '\0';
    strncpy(dir, exe, sizeof(dir));
    dir[sizeof(dir) - 1] = '\0';
    return dir;
}

static void build_path(char *dest, size_t size, const char *filename) {
    const char *dir = get_exec_dir();
    if (!dir) {
        fprintf(stderr, "Nem sikerült megtalálni az exe könyvtárát.\n");
        exit(2);
    }
    snprintf(dest, size, "%s/%s", dir, filename);
}

static void print_source(const char *display_name, const char *source) {
    printf("\n========== %s SOURCE ==========" "\n", display_name);
    fputs(source, stdout);
    printf("\n========== END OF SOURCE ==========" "\n\n");
}

static int write_file(const char *filepath, const char *content) {
    if (access(filepath, F_OK) == 0) {
        fprintf(stderr, "A fájl már létezik: %s\n", filepath);
        return 1;
    }

    int fd = open(filepath, O_WRONLY | O_CREAT | O_EXCL, 0644);
    if (fd < 0) {
        perror(filepath);
        return 1;
    }

    FILE *f = fdopen(fd, "w");
    if (!f) {
        perror("fdopen");
        close(fd);
        return 1;
    }

    if (fputs(content, f) == EOF || fclose(f) != 0) {
        perror(filepath);
        return 1;
    }

    return 0;
}

static int run_and_check(const char *command) {
    printf("Running: %s\n\n", command);
    int result = system(command);
    if (result == -1) {
        perror("system");
        return 127;
    }
    return WIFEXITED(result) ? WEXITSTATUS(result) : 1;
}

static const char *const PY_SOURCE = "#!/usr/bin/env python3\n"
"\"\"\"Egyszerű Python alap program.\"\"\"\n"
"\n"
"def main():\n"
"    print(\"Python alap program fut.\")\n"
"    print(\"A python forrás is sikeresen ki lett írva.\")\n"
"\n"
"if __name__ == '__main__':\n"
"    main()\n";

static const char *const JAVA_SOURCE = "public class Alap {\n"
"    public static void main(String[] args) {\n"
"        System.out.println(\"Java alap program fut.\");\n"
"        System.out.println(\"A Java forrás ki lett írva és lefutott.\");\n"
"    }\n"
"}\n";

static const char *const C_SOURCE = "#include <stdio.h>\n"
"int main(void) {\n"
"    printf(\"C alap program fut.\\n\");\n"
"    printf(\"A C program forrása ki lett írva és lefutott.\\n\");\n"
"    return 0;\n"
"}\n";

static const char *const SH_SOURCE = "#!/bin/bash\n"
"\n"
"echo \"Bash alap program fut.\"\n"
"echo \"A Bash forrás ki lett írva és lefutott.\"\n";

static const char *usage_text(void) {
    return "alap - Egyszerű program futtató különböző nyelveken\n\n"
           "Használat:\n"
           "  alap <nyelv>                Futtatja a <nyelv> alap programját\n"
           "  alap <nyelv> --stdout       Kiírja a <nyelv> forráskódját\n"
           "  alap                        Kiírja ezt a help-et\n"
           "  alap -h|--help              Kiírja ezt a help-et\n\n"
           "Nyelvek: py, java, c, bash\n\n"
           "Példák:\n"
           "  alap py                     Létrehozza és futtatja a Python alap programot\n"
           "  alap py --stdout            Kiírja a Python forráskódot\n";
}

int main(int argc, char *argv[]) {
    int stdout_mode = 0;
    const char *lang = NULL;

    if (argc == 1 || (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))) {
        printf("%s", usage_text());
        return 0;
    } else if (argc == 2) {
        lang = argv[1];
    } else if (argc == 3 && strcmp(argv[2], "--stdout") == 0) {
        stdout_mode = 1;
        lang = argv[1];
    } else {
        printf("%s", usage_text());
        return 1;
    }

    const char *filename = NULL;
    const char *source = NULL;
    char filepath[PATH_MAX];
    char command[PATH_MAX * 4];
    int exit_code = 0;

    if (strcmp(lang, "py") == 0 || strcmp(lang, "python") == 0) {
        filename = "alap.py";
        source = PY_SOURCE;
    } else if (strcmp(lang, "java") == 0) {
        filename = "Alap.java";
        source = JAVA_SOURCE;
    } else if (strcmp(lang, "c") == 0) {
        filename = "alap_base.c";
        source = C_SOURCE;
    } else if (strcmp(lang, "bash") == 0 || strcmp(lang, "sh") == 0) {
        filename = "alap.sh";
        source = SH_SOURCE;
    } else {
        fprintf(stderr, "Ismeretlen nyelv: %s\n", lang);
        printf("%s", usage_text());
        return 1;
    }

    if (stdout_mode) {
        print_source(filename, source);
        return 0;
    }

    build_path(filepath, sizeof(filepath), filename);
    if (write_file(filepath, source) != 0) {
        return 1;
    }

    print_source(filename, source);

    if (strcmp(lang, "py") == 0 || strcmp(lang, "python") == 0) {
        snprintf(command, sizeof(command), "python3 '%s'", filepath);
        exit_code = run_and_check(command);
    } else if (strcmp(lang, "java") == 0) {
        snprintf(command, sizeof(command), "javac '%s' && java -cp '%s' Alap", filepath, get_exec_dir());
        exit_code = run_and_check(command);
    } else if (strcmp(lang, "c") == 0) {
        char outpath[PATH_MAX];
        build_path(outpath, sizeof(outpath), "alap_base_exec");
        snprintf(command, sizeof(command), "gcc -o '%s' '%s' && '%s'", outpath, filepath, outpath);
        exit_code = run_and_check(command);
    } else if (strcmp(lang, "bash") == 0 || strcmp(lang, "sh") == 0) {
        snprintf(command, sizeof(command), "bash '%s'", filepath);
        exit_code = run_and_check(command);
    }

    return exit_code;
}
