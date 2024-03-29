todolist: todolist.o command.o add_subject.o add_subject_helpers.o remove_subject.o \
  remove_subject_helpers.o util.o add_todo_helpers.o add_todo.o clear_subject.o \
  clear_subject_helpers.o print_subject.o print_subject_helpers.o reset.o \
  remove_todo.o remove_todo_helpers.o random_todo.o initialize.o move_todo.o \
  display_subjects.o change_username.o information.o move_todo_helpers.o show_todos.o

add_subject.o: add_subject.c util.h add_subject.h add_subject_helpers.h \
 remove_subject_helpers.h initialize.h
add_subject_helpers.o: add_subject_helpers.c util.h add_subject_helpers.h \
 initialize.h
add_todo.o: add_todo.c add_todo.h util.h add_todo_helpers.h \
 remove_subject_helpers.h
add_todo_helpers.o: add_todo_helpers.c add_todo_helpers.h util.h \
 print_subject_helpers.h initialize.h
change_username.o: change_username.c change_username.h util.h \
 initialize.h
clear_subject.o: clear_subject.c clear_subject.h util.h \
 remove_subject_helpers.h clear_subject_helpers.h
clear_subject_helpers.o: clear_subject_helpers.c clear_subject_helpers.h \
 util.h initialize.h
command.o: command.c command.h util.h initialize.h
display_subjects.o: display_subjects.c display_subjects.h util.h
information.o: information.c information.h util.h initialize.h
initialize.o: initialize.c initialize.h util.h
move_todo.o: move_todo.c move_todo.h util.h move_todo_helpers.h
move_todo_helpers.o: move_todo_helpers.c util.h remove_todo_helpers.h \
 print_subject_helpers.h move_todo_helpers.h
print_subject.o: print_subject.c print_subject.h util.h \
 print_subject_helpers.h
print_subject_helpers.o: print_subject_helpers.c util.h \
 print_subject_helpers.h
random_todo.o: random_todo.c random_todo.h util.h
remove_subject.o: remove_subject.c remove_subject.h util.h \
 remove_subject_helpers.h
remove_subject_helpers.o: remove_subject_helpers.c \
 remove_subject_helpers.h util.h initialize.h
remove_todo.o: remove_todo.c util.h remove_todo.h remove_todo_helpers.h
remove_todo_helpers.o: remove_todo_helpers.c util.h remove_todo_helpers.h \
 print_subject_helpers.h
reset.o: reset.c reset.h util.h remove_subject_helpers.h initialize.h
show_todos.o: show_todos.c show_todos.h util.h print_subject_helpers.h
todolist.o: todolist.c command.h util.h add_subject.h remove_subject.h \
 add_todo.h clear_subject.h print_subject.h reset.h remove_todo.h \
 random_todo.h display_subjects.h change_username.h information.h \
 move_todo.h initialize.h
util.o: util.c util.h initialize.h


clean:
	rm *.o todolist
