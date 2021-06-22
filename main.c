#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (){
				 int index=0 , n , j , k , flag, i;
				
				//read n and k
				scanf("%d %d" , &n , &k);
				int array[n];
				
				//getting input
				for(i=0 ; i<n ;i++){
								scanf("%d" , &array[i]);
				}
				
				
				//initialzing occurances
				int dis[n][2];
					for(i=0 ; i<n ;i++){
dis[i][1] = 1 ;								
				}
				
				// creating a second array
					for(i=0 ; i<n ;i++){
				flag = 0 ; // zero means its a new value	 , we assume array[i] to be so
								for(j=0 ; j<i ; j++){
												
												if(array[i] == dis[j][0]) {dis[j][1] ++; flag=1;}
												
								}
								
								// if flag hasnt been changed to 1 , it's indeed a new value
							if(flag==0) {	dis[index][0] = array[i] ; index++; }
				}
	
                // SORTIING
								
				int *temp [2] ;
				for(j=0 ; j<k ; j++){
								
				for(i=0 ; i<index-1 ; i++){
								if (dis[i][0] > dis[i+1][0]){
	// an extremely ineffecient sorting algorithm , but we dont need to sort the whole array									
																		
                   memcpy(temp , dis[i] , 8) ;			// 8 bits bcs we need to copy BOTH the value and its occurance									
                   memcpy( dis[i] ,dis[i+1]  ,8 ) ;												
				              memcpy( dis[i+1] , temp, 8) ;												
								                                         }
								
				}
				
				
				}
				long int sum=0 ;
 
	
				// we sum up the k-th latest (ie biggest) values of the sorted array			
				
				for(i=index-k ; i<=index-1; i++ ){
								
								sum+= dis[i][0] * dis[i][1] ;
								
				}				
				
				printf("%ld" , sum) ;
				
				
				return 0;
}