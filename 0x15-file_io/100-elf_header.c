#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <errno.h>
#include "main.h"

/**
 * display_error - Display an error message and exit with status code 98
 * @msg: The error message to display
 */
void display_error(const char *msg)
{
    dprintf(STDERR_FILENO, "Error: %s\n", msg);
    exit(98);
}

/**
 * print_elf_header - Display information from the ELF header
 * @elf_header: Pointer to the ELF header structure
 */
void print_elf_header(Elf64_Ehdr *elf_header)
{
    printf("Magic: %x %x %x %x\n",
           elf_header->e_ident[EI_MAG0],
           elf_header->e_ident[EI_MAG1],
           elf_header->e_ident[EI_MAG2],
           elf_header->e_ident[EI_MAG3]);

    printf("Class: %s\n",
           elf_header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");

    printf("Data: %s\n",
           elf_header->e_ident[EI_DATA] == ELFDATA2LSB ?
           "2's complement, little endian" : "2's complement, big endian");

    printf("Version: %d\n", elf_header->e_ident[EI_VERSION]);
    printf("OS/ABI: %d\n", elf_header->e_ident[EI_OSABI]);
    printf("ABI Version: %d\n", elf_header->e_ident[EI_ABIVERSION]);
    printf("Type: %d\n", elf_header->e_type);
    printf("Entry point address: %lx\n", (unsigned long)elf_header->e_entry);
}

/**
 * main - Entry point of the program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr elf_header;

    if (argc != 2)
        display_error("Usage: elf_header elf_filename");

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        display_error("Cannot open file");

    if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
        display_error("Cannot read ELF header");

    if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0)
        display_error("Not an ELF file");

    print_elf_header(&elf_header);
    close(fd);
    return (0);
}

