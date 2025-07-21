#include <stdio.h>
#include "inst_c.h"

void emit_yaml(const char* file) {
    FILE* out = fopen(file, "w");
    if (!out) {
        perror(file);
        return;
    }
    // Output as YAML file
    for (int i = 0; i < INSTRUCTION_COUNT; ++i) {
        fprintf(out, "name: \"%s\"\n", instructions[i].name);
        fprintf(out, "long_name: \"%s\"\n", instructions[i].long_name);
        fprintf(out, "description: |\n");
        const char *desc = instructions[i].description;
        // Print description with indented newlines
        while (*desc) {
            fprintf(out, "  ");
            while (*desc && *desc != '\\') {
                fputc(*desc++, out);
            }
            if (*desc == '\\' && desc[1] == 'n') {
                fputc('\n', out);
                desc += 2;
            }
        }
        fprintf(out, "\nassembly: \"%s\"\n", instructions[i].assembly);
        fprintf(out, "match: \"%s\"\n", instructions[i].match);
    }
    fclose(out);
    printf("Emitted YAML to %s\n", file);
}

int main() {
    emit_yaml("gen.yaml");
    return 0;
}
