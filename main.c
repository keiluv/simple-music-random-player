#include <stdio.h>
//이번 코드에서는 random을 사용할 것이기에 rand함수가 포함된 stdlib.h 헤더파일을 이용합니다.
#include <stdlib.h>
// 시간마다 rand함수를 통해 값을 바꾸기 위해서 time.h 헤더파일을 이용합니다.
#include<time.h>

//매크로를 이용해 반복값되는 값을 대체
#define SIZE 20
#define AMOUNT 5

int main(void) {
    //변수 설정
    char song[AMOUNT][SIZE];//노래제목 변수
    int turn[AMOUNT];//노래순서 변수
    
    //시간을 기준으로 초기화하여 난수를 생성하게 도움
    srand(time(NULL));

    //노래 제목 입력받기
    for(int i =0;i<AMOUNT;i++){
        printf("노래 제목을 입력하시오\n");
        scanf("%s",song[i]);
    }

    //재생할 노래 순서 변수 랜덤 설정
    for(int i=0;i<AMOUNT;i++){
        //rand()함수는 값을 랜덤하게 정해주는 함수로 rand() 뒤에 %가 나오며 그 뒤에 나오는 값에 따라 범위가 0~(%뒤의 값-1)으로 정해진다.
        turn[i]=rand()%AMOUNT;//0~(AMOUNT-1)
        
        //중복값을 제거하기 위해 i번째 값과 i번째 이전 값들을 반복문을 통해 하나씩 비교하여 중복값이 나올 시에 i에 1을 뺌으로써 다시 값을 랜덤하게 설정한다.
        for(int j=0;j<i;j++){
            if(turn[i]==turn[j]){
                //i에 1을 뺌으로써 28번째 줄의 turn[i] 랜덤 설정 단계로 돌아간다.
                i--;
                //반복문 탈출
                break;
            }
        }
    }

    printf("\n------재생목록------\n\n");

    //노래 제목을 랜덤하게 보여준다. 그 방법은 노래 제목 배열 부분에 랜덤하게 생성한 노래 순서 변수를 넣는다.
    for(int i=0;i<AMOUNT;i++){
        printf("%d : %s\n",i+1,song[turn[i]]);
    }
    
    return 0;
}