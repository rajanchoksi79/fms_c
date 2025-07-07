#ifndef file_op_two
#define file_op_two

int delete_file(char *path);
int rename_file(char *path_one, char *path_two);
int move_file(char *path_one, char *path_two);
int copy_file(char *path_one, char *path_two);

#endif