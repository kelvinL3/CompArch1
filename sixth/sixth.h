//globals
int size;


//check that string is only letters
int validString(char *str);

//add '1' and grow string by 1
char *growString(char *str, int index);

//cut out [low, high], inclusive, replace with char and number
char *cutOutFromString(char *str, int low, int high);