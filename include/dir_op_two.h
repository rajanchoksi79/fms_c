#ifndef dir_op_two
#define dir_op_two

int move_directory(char *rel_path);
const char *get_basename(const char *rel_path);
int print_directory_content(const char *rel_path, const struct stat *stat_buf, int typeflag, struct FTW *ftw_buf);
int read_directory_rec(char *path);
int remove_directory_content(const char *rel_path, const struct stat *stat_buf, int typeflag, struct FTW *ftw_buf);
int remove_directory_rec(char *path);

#endif