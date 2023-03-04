#include <stdio.h>

float read_file( char* file_path) {
    FILE *file = fopen(file_path, "rb");
    if (file==NULL) {
        return -1;
    }
    int byte;
    int byte_ascii;
    double number = 0;
    int sign = 1;
    int index = 0;
    int point_index = 0;
    while((byte = fgetc(file)) != EOF){
        byte_ascii = byte;
        if (byte_ascii == 45) {
            sign = -1;
        }
        if (byte_ascii == 46 || byte_ascii == 44) {
            point_index = index;
        }
        if (48 <= byte_ascii && byte_ascii <= 57){
            number *= 10; 
            number += byte_ascii-48;
        index++;
        }
    }
    number *= sign;
    for (int i = 0; i < index - point_index; i++) {
        number = number / 10;
    }
    return number;
}
float read_x(){
    float x = read_file("x.txt");
    return x;
}

float read_y(){
    float y = read_file("y.txt");
    return y;
}

float calculate(float x, float y){
    return ( ( x * x ) + ( y * y ));
}

void write_result(float result){
    FILE *file;
    file = fopen("result.txt", "w");
    fprintf(file, "%f", result);
    fclose(file);
}

int main() {
    float x = read_x();
    float y = read_y();
    float result = calculate(x, y);
    printf("X:\t%f\nY:\t%f\n\n",x, y);
    printf("Result:\t%f", result);
    write_result(result);
    return 0;
}