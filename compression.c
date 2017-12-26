#include "my.h"
void compression(DblLinkedList *list){
    resistor *start = list->head;
    unsigned char m;
    long long s[256]={0};
    double ch[256]={0}, sum = 0, high,high_new,low,low_new, low_old, high_old,high_cur, low_cur;
    FILE *f;
    int i=0,count=0,n=0,len[20]={-1};
    resistor *current;
    char filename[21];
    printf("Warning! This compression works only on the field of the string type (the name of the compiler) and encodes no more than 10 symbols\n");
    current = start;
    f = fopen("temp", "wb");
    if (f == NULL) {
        fclose(f);
        printf ( "1)Compression error!\n" ) ;
        return;
        }
    i=0;
    while(current != NULL && i < 20){
        fwrite(current->name, sizeof(current->name), 1, f);
        count += strlen(current->name);
        len[i] = strlen(current->name);
        current = current->next;
        i++;
    }
    fclose (f);
    if(count > 10){
        printf("Compression error! encoded for more than 10 characters\n");
        return;
    }
    f=fopen("temp", "rb");
    if (f == NULL) {
        system("clear");
        fclose(f);
        printf ( "2)Error while compressing the file!\n" );
        return;
    }
    i=0;
    printf("Compressing data!\n");
    while(1){
        fread(&m, sizeof(m), 1, f);
        //printf("%c\n", m);
        s[m]++;
        if (feof(f)) break;
        else i++;
    }
    s[ 0 ] = 0;
    for(i = 0; i < 256; i++){
        ch[i]=(double) s[i]/count;
    }
    for (i = 0; i < 256; i++){
        sum += ch[i];
        ch[i] = sum;
    }
    puts("Коды и интервал\n");
    for(i=0; i<256; i++)
    printf("%c  %f\n", i, ch[i]);
    fseek(f, 0, SEEK_SET);
    low_new = 0; high_new = ch[255];
    while(!feof(f)){
        fread(&m,sizeof(m),1,f);
        low_cur= m==0 ? 0 : ch[m-1] ;
        high_cur=ch[m];
        low_old=low_new;
        high_old=high_new;
        if(ch[m] >= ch[m-1]){
            high_new=low_old+(high_old-low_old)*high_cur;
            low_new=low_old+(high_old-low_old)*low_cur;
            low_old=low_new;
            high_old=high_new;
        }
    }
    fclose (f);
    printf("\nEnter the name of the binary file to save the compressed data:\n");
    //fgets (filename,21,stdin);
    scanf("%s", &filename);
    for(i=0; filename[i] != '\0'; i++);
    if (filename[i-1] == '\n') filename[i-1]='\0';
    else
        while(getchar() != '\n');
            f = fopen(filename, "wb");
    if (f == NULL) {
    printf ("Не удалось открыть файл!\n");
    fclose(f);
    return;
    }
    fwrite(ch, sizeof(double), 256, f);
    low = (low_new+high_new)/2.;
    fwrite(&low, sizeof(low), 1, f);
    fwrite(&high_new, sizeof(high_new), 1, f);
    fwrite(&count, sizeof(count), 1, f);
    fwrite(len, sizeof(int), 20,f);
    fclose(f);
    system("clear");
    printf ( "Compression was succsessful!\n" );
}
