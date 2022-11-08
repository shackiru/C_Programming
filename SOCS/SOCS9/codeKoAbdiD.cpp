#include<stdio.h>
#include<string.h>

int main(){
	int tc;
	int total[30];
	int jawab[10]={0};
	int arr[30];
	int max=0;
	int min=20000001;
	int idxMax=-1;
	int idxMin=-1;
	
	for(int i=0; i<30; i++){
		arr[i]=0;
	}
	
	scanf("%d", &tc);
	for(int i=0; i<tc; i++){
		for(int j=0; j<5; j++){
			jawab[j]=0;
		}
		for(int j=0; j<30; j++){
			arr[j]=0;
			total[j]=0;
		}
		max=0;
		min=20000001;
		idxMax=-1;
		idxMin=-1;
		for(int j=0; j<25; j++){
			scanf("%d", &total[j]);
			arr[j]++;
			if(max<total[j]){
				max=total[j];
				idxMax=j;
			}
			if(min>total[j]){
				min=total[j];
				idxMin=j;
			}
			for(int k=0; k<j; k++){
				if(total[j]==total[k]){
					arr[j]--;
					arr[k]++;
					break;
				}
			}
		}
		printf("Case #%d:", i+1);
		if(arr[idxMax]==1){
			jawab[4]=max/2;
		}
		if(arr[idxMin]==1){
			jawab[0]=min/2;
		}
		if(arr[idxMax]==4){
			jawab[4]=max/2;
			jawab[3]=max/2;
		}
		if(arr[idxMin]==4){
			jawab[0]=min/2;
			jawab[1]=min/2;x
		}
		if(arr[idxMax]==9){
			jawab[4]=max/2;
			jawab[3]=max/2;
			jawab[2]=max/2;
		}
		if(arr[idxMin]==9){
			jawab[0]=min/2;
			jawab[1]=min/2;
			jawab[2]=min/2;
		}
		if(arr[idxMax]==16){
			jawab[4]=max/2;
			jawab[3]=max/2;
			jawab[2]=max/2;
			jawab[1]=max/2;
		}
		if(arr[idxMin]==16){
			jawab[0]=min/2;
			jawab[1]=min/2;
			jawab[2]=min/2;
			jawab[3]=min/2;
		}
		if(arr[idxMin]==25){
			jawab[0]=min/2;
			jawab[1]=min/2;
			jawab[2]=min/2;
			jawab[3]=min/2;
			jawab[4]=min/2;
		}		
		
		for(int j=0; j<25; j++){
			if((total[j]%2==0)&&(arr[j]==1 || arr[j]==3 || arr[j]==5) && total[j]!=max && total[j]!=min){
				for(int k=0; k<5; k++){
					if(jawab[k]==0){
						jawab[k]=total[j]/2;
						break;
					}
				}
			}
		}
		for(int j=0; j<5; j++){
			for(int k=0; k<4-j; k++){
				if(jawab[k]>jawab[k+1]){
					int cont;
					cont=jawab[k];
					jawab[k]=jawab[k+1];
					jawab[k+1]=cont;
				}
			}
		}
		for(int j=0; j<5; j++){
			printf(" %d", jawab[j]);
		}
		printf("\n");
	}			
	return 0;
}
