#ifndef STRUCT_CSV_H_INCLUDED
#define STRUCT_CSV_H_INCLUDED

struct bike_components {
    char *name;
    char *type;
    int year;
    float cost;
    int reviews;
    float rating;
};
typedef struct bike_components comps;


char **simple_split(char *str, int length, char sep);
void ClearStringArray(char **str, int n);
comps *struct_fill(char **str);
comps *new_struct();
void print_header();
void struct_out(comps *str0);
void ClearStructure(comps *str0);


#endif // STRUCT_CSV_H_INCLUDED
