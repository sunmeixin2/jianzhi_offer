#include<stdio.h>
#include<string.h>
void Permutation(char *pstr,char* pBegin){
	
	if(*pBegin=='\0'){
		printf("%s\n",pstr);
	}else{
		char *pch;
		for(pch=pBegin;*pch!='\0';++pch){
//			if(*pch==*pBegin)
//				continue;
//			else{
				char temp=*pch;
				*pch=*pBegin;
				*pBegin=temp;
				
				Permutation(pstr,pBegin+1);
				temp=*pch;
				*pch=*pBegin;
				*pBegin=temp;
			//}
		}
	}
	
	
	
}
int main(){
	char *str="abc";
	Permutation(str,str);
	return 0;

} 
