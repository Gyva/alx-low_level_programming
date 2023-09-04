#include "main.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>

void print_error(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(98);
}

void print_elf_header_info(Elf64_Ehdr *header) {
    printf("Magic: ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x", header->e_ident[i]);
        if (i < EI_NIDENT - 1) {
            printf(" ");
        }
    }
    printf("\n");

    printf("Class: %s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : (header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "Invalid"));
    printf("Data: %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : (header->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "Invalid"));
    printf("Version: %d\n", header->e_ident[EI_VERSION]);

    printf("OS/ABI: %d\n", header->e_ident[EI_OSABI]);
    printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

    printf("Type: %d\n", header->e_type);
    printf("Entry point address: 0x%lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }

    const char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        print_error(strerror(errno));
    }

    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        print_error(strerror(errno));
    }

    if (file_stat.st_size < sizeof(Elf64_Ehdr)) {
        print_error("File size is smaller than ELF header size");
    }

    Elf64_Ehdr elf_header;
    if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header)) {
        print_error("Failed to read ELF header");
    }

    if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0) {
        print_error("Not an ELF file");
    }

    print_elf_header_info(&elf_header);

    close(fd);

    return 0;
}

