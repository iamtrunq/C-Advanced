#include <stdio.h>
#include <stdlib.h>


struct typeArr{
	int *arr;
	int size;
};
struct typeArr *NhapThongTin(){
	
	static struct typeArr arr;
	
	int *ptr;
	int size;
	
	printf("Nhap kich thuoc cua mang: ");
	scanf("%d",&size);
	
	ptr=(int*)malloc(size*sizeof(int));
	
	for (int i= 0; i< size; i++){
		printf("Gia tri thu %d cua mang la: ",i);
		scanf("%d",&(ptr[i]));
	
	}
	
	arr.size=size;
	arr.arr=ptr;
	return &arr;
	
}

void mintomax(struct typeArr *value){
	int tg;
	int i,j;
	for(i= 0;i < value->size-1; i++){
		for(j = i+ 1; j < value->size; j++){
			if(value->arr[i]> value->arr[j]){
				tg= value->arr[i];
				value->arr[i]=value->arr[j];
				value->arr[j]=tg;
				
			}
		}		
	}
	printf("\nMang sau khi sap xep tu be de lon: \n");
	for (int i = 0; i< value->size;i++){
		printf("%d\n",value->arr[i]);
	}
	
}

void maxtomin(struct typeArr *value){
	int tg;
	int i,j;
	for (int i= 0; i < (*value).size-1;i++){
		for( j= i+ 1; j< (*value).size;j++){
			if((*value).arr[i]<(*value).arr[j]){
				tg= (*value).arr[i];
				(*value).arr[i]=(*value).arr[j];
				(*value).arr[j]=tg;		
				
			}
		}
	}
	printf(" \n Mang sau khi xep sep tu lon den be la :\n");
	for(int i= 0; i< value->size; i++){
		printf("%d\n",value->arr[i]);
	}
}

void max(struct typeArr *value ){
	int max;
	value->arr[0];
	
	for (int i=1; i < value->size;i++){
		if (value->arr[0]<value->arr[i]){
			max = value->arr[i];
		}
	}
	printf("\n Gia tri lon nhat la %d\n",max);
	
}

int main(){
	struct typeArr *test;
	test=NhapThongTin();
    //for(int i= 0; i< test->size; i++){
	//	printf("ptr[%d] : %d \n",i,test->arr[i]);
	//}
	int option;
	printf("Option ? \n");
	printf("1 : MaxToMin\n2 : MinToMax \n3 : Max \n4 : Exit \n");
	printf("Vui long nhap lua chon cua ban ??? \n");
	scanf("%d",&option);
	switch(option){
		case 1 :
			maxtomin(test);
			break;
		case 2 :
			mintomax(test);
			break;
		case 3 : 
			max(test);
			break;
		case 4 : 
			exit(0);
			break;
		default:
			printf("Vui long nhap dung dinh dang");
			break;
	}
	return 0;
}
