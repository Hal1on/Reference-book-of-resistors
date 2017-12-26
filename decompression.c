#include "my.h"
resistor* decompression(DblLinkedList *list){
    resistor *start = list->head;
    FILE *f;
    long long N, i, j;
    double N_prov, size;
    resistor *new, *current;
    double ch[256]={0}, low, high, low_o, high_o;
    int count,k,n,len[20]={-1};
    unsigned char m;
    char filename[21];
    char name[41]={'\0'};
    printf("Enter the filename, for open and decompression:\n");
    scanf("%s", &filename);
    //fgets(filename, 21, stdin);
    for(i=0; filename[i]!='\0'; i++);
        if(filename[i-1]=='\n')
            filename[i-1]='\0';
        else
            while(getchar()!='\n');
                f=fopen(filename, "rb");
    if (f == NULL) {
        printf ("Can't open file!\n");
        return start;
    }
    fread(ch,sizeof(ch),1,f);fread(&low,sizeof(low),1,f);
    fread(&high,sizeof(high),1,f);
    fread(&count,sizeof(count),1,f);
    fread(len,sizeof(len),1,f);
    fclose(f);
    if(!count){
        printf("Error decompression!\n");
        return start;
    } else {
        current=start;
        remove1(start);
        start=NULL;
    }
    f=fopen("temp", "wb");
    if (f==NULL) {
        printf ( "1)Error decompression !\n" ) ;
        return start;
    }
    for(i=0; i<count; i++){
        m=0;
        for(j=0; j<255; j++){
            high_o = ch[j];
            low_o = j==0 ? 0 : ch[j-1] ;
            if(low <= high_o &&  low_o < low){
                m =( unsigned char) j;
                fwrite(&m, sizeof(m), 1, f);
                printf("Decompression of symbol%c\n", m);
                printf("his code is:%f\n\n",low);
                low = (low-low_o)/(high_o-low_o);
                break;
            }
        }
    }
    fclose(f);
    f=fopen("temp", "rb");
    if (f==NULL){
        system("clear");
        printf ("We can't read th.\n");
        return start;
    }
    fseek(f, 0, SEEK_SET);
    for(i=0; i<20 && len[i]!=0; i++){
        new = malloc(sizeof(resistor));
        for(j=0; j<len[i]; j++){
        m=getc(f);
        if (feof(f)) break;
        new->name[j]=m;
        }
        new->name[j]='\0';
        if (start==NULL){
            start=new;
            new->next=NULL;
        } else {
            current=start;
            while(current->next!=NULL)
                current=current->next;
            current->next=new;
            new->next=NULL;
        }
    }
    fclose(f);
    system("clear");
    printf("load from file %s was success!\n", filename);
    return start;
}
