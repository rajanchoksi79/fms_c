#ifndef file_op_three
#define file_op_three

int states_file(char *path);
int change_file_permission(char *path, mode_t per_code);
mode_t parse_octal_mode(char *input);
int help_user();

#endif