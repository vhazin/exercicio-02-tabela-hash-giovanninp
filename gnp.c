#include <stdio.h>
#include <stdlib.h>

typedef struct Element{
    int modelValue;
    int value;
    int position;
}element;

int checkExistence(int val,element *els,int size){
    int result = 0;
    for(int i=0;i<size;i++){
        if(els[i].value == val){
            result = 1;
        }
    }
    return result;
}

void caseMaker(int caseNum){
    int caseInputs[2];
    int lines;
    int columns;
    for(int rep = 0;rep<2;rep++){
        scanf("%d",&caseInputs[rep]);
    }   
    lines = caseInputs[0];
    columns = caseInputs[1];


    element elements[caseInputs[1]];

    int finalTable[caseInputs[0]][caseInputs[1]];

    for(int l=0;l<caseInputs[1];l++){
        scanf("%d",&elements[l].value);
        elements[l].modelValue = elements[l].value % caseInputs[0];
        elements[l].position = 0;
        for (int x = 0;x<l;x++){
            if((elements[l].modelValue == elements[x].modelValue)){
                elements[l].position++;
            }
        }
    }   
    for (int line=0;line<caseInputs[0];line++){
        for (int el=0;el<caseInputs[1];el++){
            if(elements[el].modelValue == line){
                finalTable[line][elements[el].position] = elements[el].value;
            }
        }
    }
    printf("%d",finalTable[1][1]);

    printf("%d",caseInputs[0]);
    
    for(int liner=0;liner<lines;liner++){
        printf("\n%d",liner);
        for(int cont=0;cont< columns;cont++){
            if((liner < caseInputs[0])&&(cont < caseInputs[1])){
                if(finalTable[liner][cont] <= 0){
                    printf(" -> \\");
                    break;
                    }
                else if((cont < columns)&& (checkExistence(finalTable[liner][cont],elements,columns))){
                    printf(" -> %d",finalTable[liner][cont]);
                }
            }
        } 
    }
}

int main(void){
    int caseNum;
    scanf("%d",&caseNum);
    for (int rep=0;rep<caseNum;rep++){
        caseMaker(caseNum);
    }
    return 0;
}
