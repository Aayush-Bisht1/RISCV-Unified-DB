import yaml

# This script reads a YAML file and generates a C header file with instruction data.
yaml_file = "c.addi.yaml"      
header_file = "inst_c.h"

def parse_and_emit_header(yaml_path, header_path):
    with open(yaml_path) as f:
        data = yaml.safe_load(f)

    with open(header_path, "w") as h:
        h.write("// Generated from {}\n".format(yaml_path))
        h.write("#ifndef INST_DATA_H\n#define INST_DATA_H\n\n")
        h.write("typedef struct {\n")
        h.write("    const char* name;\n")
        h.write("    const char* long_name;\n")
        h.write("    const char* description;\n")
        h.write("    const char* assembly;\n")
        h.write("    const char* match;\n")
        h.write("} instruction_t;\n\n")
        h.write("static const instruction_t instructions[] = {\n")
        h.write('    {"%s", "%s", "%s", "%s", "%s"}\n' % (
            data.get("name", ""),
            data.get("long_name", ""),
            data.get("description", "").replace('\n', '\\n').replace('"', '\\"'),
            data.get("assembly", ""),
            data.get("encoding", {}).get("match", "")
        ))
        h.write("};\n\n")
        h.write("#define INSTRUCTION_COUNT 1\n")
        h.write("#endif // INST_DATA_H\n")

parse_and_emit_header(yaml_file, header_file)
print(f"Header {header_file} generated from {yaml_file}")
