#include<stdio.h>
#include<stdbool.h>

typedef struct Node{
	int x;
	int y;
	int width;
	int height;
}rect;

int isOverlap(rect rc1,rect rc2){
	
	if(rc1.x<rc2.x+rc2.width &&
	   rc2.x<rc1.x+rc1.width &&
	   rc2.y-rc2.height<rc1.y &&
	   rc1.y-rc1.height<rc2.y
	)
		return true;
	else
		return false;

}
int main(){
	rect rc1,rc2;
	printf("input rc1:");
	scanf("%d %d %d %d",&rc1.x,&rc1.y,&rc1.width,&rc1.height);
	printf("\ninput rc2:");
	scanf("%d %d %d %d",&rc2.x,&rc2.y,&rc2.width,&rc2.height);
	
	if(isOverlap(rc1,rc2)){
		printf("true");
	}else{
		printf("false");
	}
         printf("\n");
}
