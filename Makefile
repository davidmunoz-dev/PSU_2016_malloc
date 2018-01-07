##
## Makefile for  in /home/munoz_d/PSU_2016_malloc
## 
## Made by David Munoz
## Login   <david.munoz@epitech.eu>
## 
## Started on  Fri Jan 27 11:25:00 2017 David Munoz
## Last update Thu Feb  9 23:45:46 2017 hazer
##

TARGET	 = libmy_malloc_$(HOSTTYPE).so

LINK	 = libmy_malloc.so

CC	 = gcc

SRC      = my_malloc.c		\
	   memory.c		\
	   show_alloc_mem.c	\
	   my_free.c		\
	   my_realloc.c		\

CFLAGS   = -W -Werror -Wall -ansi -pedantic -Iinclude -fPIC -shared -lpthread -std=gnu99

SRCDIR   = src
OBJDIR   = obj

SOURCES  := $(addprefix src/, $(SRC))

OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

rm       = rm -rf
mkdir    = mkdir -p

$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS)
	@ln -sf $(TARGET) $(LINK)
	@echo $(TARGET)" compiled !"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(mkdir) $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all     : $(TARGET)

clean   :
	@$(rm) $(OBJDIR)
	@echo "Binary files deleted"

fclean  : clean
	@$(rm) $(TARGET) $(LINK)
	@echo "Binary and executable files are deleted"

re      : fclean all

.PHONY: all clean fclean re
