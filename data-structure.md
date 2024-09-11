# 2024 자료구조 포트폴리오
## 20418 - 최진호

>from 2024-08-20<br>
>to - -
<br></br>


## Index
* [1,2차시 - 정렬](#c2)
* [3차시 - 선택 정렬](#c3)
* [4차시 - 삽입 정렬](#c4)
* [🔔중간퀴즈 1 - 삽입정렬](#q1)
* [5,6차시 - 버블 정렬](#c5)
* [7차시 - 발표1(해시함수_유재희)](#c7)
* [8차시 - 쉘 정렬](#c8)
* [9차시 - 발표2(RSA암호화 알고리즘_송혜인, 이진탐색트리 구현_박찬규)](#c9)
* [10,11차시 - 발표3(데이터베이스 인덱스_유도윤, 절차적 맵 생성_이정훈)](#c10)
* [발표 기록](#record)
* [노트](#note)


<br><br/>
<br><br/>
<br><br/>
<br><br/>
<br><br/>
<br><br/>
<br><br/>
<br><br/>
<br><br/>
<br><br/>
<!-- 여기 부터 -->


<br id='c2'></br>
<!-- 2024-08-20 -->
# 2024-08-20  1,2차시 - 정렬

---------------------------

## 정렬 : 크기순으로 나열하는 것

컴퓨터 과학에서....
정렬의 기준을 Record 라고 하고 이는 Field 로 구성됨
특정 Record 를 식별하려고 사용되는 Field 를 Key 라고 함
정렬을 레코드 들을 키 값의 순서고 재배열 하는 것

예시 : 학생들의 레코드
![레코드](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQ6wFwlRS_VmgFfOLTIuUEOX8d8AEBQpAaaYQ&s)

## 정렬의 종류

* 복잡도 밑 효율성에 따라
  * 단순 but 비효율
    * 삽입정렬, 선택정려르 버블정렬 등
  * 복잡 but 효율
    * 퀵 정렬, 힙 정렬, 합병 정렬, 기수 정렬 등
* 정렬 대상의 주기억 장치 적재 여부에 따라
  * 내부정렬
  * 외부정렬
* 안정성에 따라
  * 동일한 키 값을 갖는 레코드 들이 정렬 후 에도 유지 되는지

## 알고리즘 성능 평가

프로그램의 수행기산은 수행환경에 따라 유동적임

* 언어, 하드웨어, OS, 컴파일러
* 문자열 구현방법, 인자 전달방법
* 입력 크기 & 특성

> 알고리즘의 수행시간은 __반복문이 수행되는 횟수로__ 측정함

### 시간 복잡도 Time Complexity

* 알고리즘 실행 중 수행하는 기본적인 연산의 수를 입력의 크기에 대한 함수로 표현
  * 가장 널리 사용되는 알고리즘 수행시간 기준
* 기본적인 연산

#### 시간 복잡도가 높다?

> 입력의 크기가 증가할 때 알고리즘 수행시간이 더 빠르게 증가
> 시간 복잡도가 낮다고 해서 언제나 더 빠르게 동작하는 것은 아님

### 입력의 종류와 형태에 따른 수행 시간의 변화

입력에 따른 수행시간 변화를 고려하기 위해 __최선, 최악, 평균__ 수행시간 사용
일반적으로 최악 수행시간 사용

### 시간복잡도는 계산 하기 어려움

* 빅오 표기법 : 최악의 경우
* 세타 표기법 :




<br id='c3'></br>
<!-- 2024-08-22 -->
# 2024-08-22  3차시 - 선택 정렬

## 선택 정렬 Selection Sort

리스트에서 __최솟값을 선택__ 하여 첫번째 요소와 교환하는 정렬 기법

1. 두개의 리스트를 사용한 선택정렬
    * 배열이 하나 더 필요함
    * 메모리 효율적이지 않음
2. 제자리 정렬
    * 메모리 효율적임

### 제자리 선택정렬 코드 - "20240822_code.c"

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

void selSort(int list[], int n)
{
    int i, j, least, temp;
    for (i = 0 ; i < n - 1 ; i++) {     //마지막 인덱스는 자신과 비교할 필요 없음 -> n - 1 까지 반복
        least = i;      //최솟값을 첫번째 요소라고 가정
        for (j = i + 1 ; j < n ; j++) {
            if (list[j] < list[least])      //최솟값 비교
                SWAP(list[i], list[j], temp);
                least = j;
        }
    }
}

int main()
{
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for (i = 0 ; i < n ; i++)
        list[i] = rand() % 100; // 난수 발생 범위 0 ~ 99
    printf("** Selection Sort **\n\n");
    printf("Before Sorting\n");
    for (i = 0 ; i < n ; i++) // 정렬 전
        printf("%d ", list[i]);
    selSort(list, n); // 정렬
    printf("\n\nAfter Sorting\n");
    for (i = 0 ; i < n ; i++) // 정렬 후
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}
```

[참고: https://gmlwjd9405.github.io/2018/05/06/algorithm-selection-sort.html](https://gmlwjd9405.github.io/2018/05/06/algorithm-selection-sort.html)

### 이 코드의 시간복잡도 분석

* 비교 횟수
  * if 가 이중 for 문 안에 있다 -> n^2
* 이동 횟수
  * SWAP이 for 문 안에 있는데 SWAP 은 3개의 연산 -> 3 * (n - 1)
* 안정성?




<br id='c4'></br>
<!-- 2024-08-27 -->
# 2024-08-27  4차시 - 삽입 정렬

## 삽입정렬

리스트의 모든 요소를 앞에서 부터 이미 __정렬된 부분과 비교하여 자신의 위치를 찾아 삽입__ 하는 정렬.

### 삽입정렬이 효율적인 경우
1. 이미 많이 정렬된 경우

![삽입정렬](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEg4AjYYdhM_rfCeM5yHNwQVu1RPgo0wBizOKq0ESl-n8F2AI5JgWr4DKAxI-Lphlt2LlZoLCtZv1bxHYnwoU0qefj38SWF2iOURAA3pvkVyoTZevA7i7PnKNDQzAHDgz0Tl6jtp3v0AaXA/s1600/%EC%82%AC%EC%9A%A9%EC%9E%90+%EC%A7%80%EC%A0%95+12.gif)

### 삽입정렬 코드 - "20240827_code.c"

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

void insSort(int list[], int n)
{
    for ( int i = 1 ; i < n - 1 ; i++) {    //인덱스 0은 정렬된 것으로 간주.
        int j, key;
        key = list[i];  //삽입될 위치 i의 값 복사
        j = i - 1;  //현재 정렬된 부분은 i - 1 까지 이므로 i - 1 부터 역순으로 조사.
        while ( j >= 0 && list[j] > key ) { //배열인덱스가 정상적이고 key 보다 정렬된 배열에 있는 값이 크면 뒤 부터 한칸씩 밀기.
            list[j + 1] = list[j];
            j -= 1;
        }
        list[j + 1] = key;  //인덱스 j의 값이 key보다 작으므로 j + 1 이 key값이 됨.
    }
}

int main()
{
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for (i = 0 ; i < n ; i++)
        list[i] = rand() % 100; // 난수 발생 범위 0 ~ 99
    printf("** Insertion Sort **\n\n");
    printf("Before Sorting\n");
    for (i = 0 ; i < n ; i++) // 정렬 전
        printf("%d ", list[i]);
    insSort(list, n); // 정렬
    printf("\n\nAfter Sorting\n");
    for (i = 0 ; i < n ; i++) // 정렬 후
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}
```

<br id='q1'></br>
<!-- 퀴즈1 -->
# QUIZ1
1. [삽입정렬](#c4) 알고리즘의 성능 평가하기
    * 가장 빠르게 정렬 되는 경우는?
        * [] 정렬 되어 있는 경우 -> O(n^2)
        * 총 비교 횟수 : []
        * 총 이동 횟수 :
    * 가장 느리게 정렬 되는 경우
        * []
        * 총 비교 횟수 : []
            * 각 단계에서 []
            * 외부 루프 안의 각 반복마다 []번의 비교가 수행됨
        * 총 이동 횟수 : [] -> O[]
            * 외부 루프의 각 단계마다 [N] 번의 이동이 이루어짐
2. 




<br id='c5'></br>
<!-- 2024-08-27 -->
# 2024-08-27  5,6차시 - 버블정렬

## 버블 정렬

서로 __인접한 두 원소__ 를 검사하여 정렬하는 알고리즘

![버블정렬](https://www.programmingsimplified.com/images/c/bubble-sort.gif)     
[출처 : https://www.programmingsimplified.com/c/source-code/c-program-bubble-sort](https://www.programmingsimplified.com/c/source-code/c-program-bubble-sort)

### 버블정렬의 장/단점
* 버블정렬의 장점
    * 구현이 단순함
    * 제자리 정렬 알고리즘임
    * 이미 정렬된 데이터에 우수한 성능을 보임
    * 안정적임
* 버블정렬의 단점
    * 비효율적인 시간 복잡도
    * 특정요소가 첫번째 에서 마지막으로 이동하려면 많은 SWAP이 필요함
    * 교환(SWAP) 작업이 변경(CHANGE) 작업보다 복잡하다

### 버블정렬 코드 - "20240827_code_A.c"

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

void bubSort(int list[], int n)
{
    int temp, count;
    for (int i = n - 1 ; i > 0 ; i--) {     //최댓값이 맨 오른쪽 이므로 n - 1 부터 시작 (사이클)
        count = 0;
        for(int j = 0 ;  j < i ; j++) {     //맨 왼쪽 부터 정렬 안된 부분 까지 비교 (비교)
            if(list[j] > list[j + 1]) {     //비교하여 교환
                SWAP(list[j], list[j + 1], temp);
                count ++;      
            }
        }
        if (count == 0) {
            printf("exit ");
            break;  //SWAP이 안 이루어 졌다면 break; (early exit)
        }
    }
}

int main()
{
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for (i = 0 ; i < n ; i++)
        list[i] = rand() % 100; // 난수 발생 범위 0 ~ 99
    printf("** Bubble Sort **\n\n");
    printf("Before Sorting\n");
    for (i = 0 ; i < n ; i++) // 정렬 전
        printf("%d ", list[i]);
    bubSort(list, n); // 정렬
    printf("\n\nAfter Sorting\n");
    for (i = 0 ; i < n ; i++) // 정렬 후
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}
```

### 버블정렬 성능 분석하기(최선, 최악의 경우, Early Exit 경우로)
* 비교횟수 : 항상 모든 경우에 n(n-1)/2 이다.
* 이동횟수 : (n-1)*3
* 시간복잡도 : n개의 원소를 각각 n-1개의 다른 원소와 비교 > O(n) = n<sup>2</sup>
* 안정성을 만족? : 동일한 값을 가진 원소들의 본래 순서가 유지되기 때문에 안정성을 만족하다.



<br id='c7'></br>
<!-- 2024-09-03 -->
# 2024-09-03  7차시 - 발표1(해시함수_유재희)

## 해싱 Hashing
원본 문자를 알아볼 수 없는 문자열로 암호화 하는 것을 의미함

## 해시 함수 Hash Function
### 해시 함수?
데이터를 입력받아 해시값을 출력하는 함수
![해시함수](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fbx45DR%2FbtqDHrT3rQx%2Fw2EvrEnAwG3MqbJGINmRLk%2Fimg.png)   
[출처 : https://s1m0hya.tistory.com/27](https://s1m0hya.tistory.com/27)

### 해시함수 특징
* 입력된 값에 관계없이 고정된 길이의 해시값 출력
* 입력된 값이 다르면 다른 해시값을 출력
* 출력된 해시값으로 입력값을 유추할 수 없음 = 단방향 함수임

### 해시함수의 사용
* 암호화 : 출력값 일정, 복호화 불가능 해서 사용함.
* 자료구조 : 해시 테이블에서 인덱스를 해싱하여 검색을 빠르게 해줌.



<br id='c8'></br>
<!-- 2024-09-03 -->
# 2024-09-03  8차시 - 쉘 정렬 Sehll Sort

## 쉘 정렬 Shell Sort
Donald L. Shell 이 고안한 알고리즘.
삽입정렬에서 착안하여 만듬.

* 삽입정렬이 효율적인 경우
    * 정렬 대상이 작은 경우
    * 거의 정렬 된 데이터일 경우

* 삽입정렬이 비효율 적인 경우
    *


전체리스트를 일정 간격의 부분 리스트로 분할함.
1. 정렬해야 할 리스트를 일정한 기준에 따라 분류
2. 비연속 여러 부분 리스트 생성
3. 각 부분 리스트를 삽입정렬 로 정렬
4. 모든 부분리스트가 정렬되었다면 더 적은 개수의 부분 리스트를 만들어 정렬

### 정렬 과정
1. 정렬 대상 리스트의 각 k 번째 요소를 추출하여 부분리스트 생성
    * k를 간격 gap 으로 표현
    * 간격의 초기값 : 원소의 수 /2
    * 생성된 부분리스트의 개수는 간격의 수와 같음.

2. 각 회전마다 간격k를 반 으로 줄임.
    * k/2 가 짝수면 +1 하여 홀수로 만듬.
3. 과정2 를 간격 k가 1이 될 때 까지 반복.

![쉘 정렬](https://gmlwjd9405.github.io/images/algorithm-shell-sort/shell-sort-concepts.png)    
[출처 : https://gmlwjd9405.github.io/2018/05/08/algorithm-shell-sort.html](https://gmlwjd9405.github.io/2018/05/08/algorithm-shell-sort.html)


### 쉘 정렬의 특징
* 자료의 이동 효율성
    * 연속적이지 않은 부분 리스트에서 자료의 교환 발생 시 더큰 거리 이동
    * 교관 되는 요소들이 삽입정렬 보다는 최종 위치에 있을 가능성 높음
* 정렬 소요시간 단축
    * 부분 리스트는 이미 어느정도 정렬됨
    * 부분 리스트의 개수가 1이면 쉘 정렬은 삽입정렬을 수행하지만 일반적인 삽입정렬 보다는 빠르게 정렬됨


### 쉘 정렬 구현 - "shellSort_20418_최진호.c"
```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

void shellSort(int list[], int n) {
    for (int k = n / 2 ; k > 0 ; k /= 2) {
        if (k % 2 == 0) {
            k ++;     //짝수면 +1 하여 홀수로 변경
        }

        for (int i = 0 ; i < n ; i += k) {      //i와 k간격인 인덱스를 비교하기 위해 i += k
            int j, key;
            key = list[i];  //삽입될 위치 i의 값 복사
            j = i - k;  //현재 정렬된 부분은 i - 1 까지 이므로 i - 1 부터 역순으로 조사.
            while ( j >= 0 && list[j] > key ) { //배열인덱스가 정상적이고 key 보다 정렬된 배열에 있는 값이 크면 뒤 부터 한칸씩 밀기.
                list[j + k] = list[j];
                j -= k;
            }
            list[j + k] = key;  //인덱스 j의 값이 key보다 작으므로 j + 1 이 key값이 됨.
        }

        printf("\n\nk = %d \n", k);
        for (int i = 0 ; i < n ; i++)
            printf("%d ", list[i]);
    }
}

int main()
{
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for (i = 0 ; i < n ; i++)
        list[i] = rand() % 100; // 난수 발생 범위 0 ~ 99
    printf("** shell Sort **\n\n");
    printf("Before Sorting\n");
    for (i = 0 ; i < n ; i++) // 정렬 전
        printf("%d ", list[i]);
    shellSort(list, n); // 정렬
    printf("\n\nAfter Sorting\n");
    for (i = 0 ; i < n ; i++) // 정렬 후
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}
```

### 쉘 정렬 성능분석하기
* 시간 복잡도
    * 최악 : O(n<sup>2</sup>)
    * 평균 : O(n<sup>1.5</sup>)




<br id='c9'></br>
<!-- 2024-09-05 -->
# 2024-09-05  9차시 - 발표2(RSA암호화 알고리즘_송혜인, 이진탐색트리 구현_박찬규)

## 암호화

![암호화 방식](https://blog.kakaocdn.net/dn/bwzqHp/btrQZhbP5J6/oB19lMNdltkBAzBepUhVh1/img.png)  
[출처 : https://www.sinsiway.com/kr/pr/blog/view/412/page/9](https://www.sinsiway.com/kr/pr/blog/view/412/page/9)

함호화 키 == 복호화 키 : 비밀키 암호화  
함호화 키 != 복호화 키 : 공개키 암호화

공개키 : n, e
개인키 : n, r

오일러 피 함수?
1~n 중에서 n 과 서로소를 구하는 함수

HTTP, 공인인증서 등에서 사용됨



## 이진트리, 탐색, 이진 탐색트리
트리 : 노드들이 나무가지처럼 연결된 비선형 계층적 자료구조
이진트리 : 각 노드가 최대 2개의 자식노드를 가지는 트리
이진탐색트리 : 이진트리를 기반으로 하는 탐색을 위한 자료구조

### BST 특징
1. 모든 노드는 유일한 키를 가짐
2. 왼쪽 서브트리 키는 루트키 보다 작다.
3. 오른쪽 서브트리 키는 루트키 보다 크다.
4. 왼쪽, 오른쪽 서브트리 모두 이진탐색트리임

### 이진탐색트리의 시간 복잡도
높이 : H, 원소의 개수 : N   
O(logN)



<br id='c10'></br>
<!-- 2024-09-10 -->
# 2024-09-05  11차시 - 발표3(데이터베이스 인덱스_유도윤, 절차적 맵 생성_이정훈)
## 데이터베이스 인덱스
### index의 장단점
* 장점
    * 조회속도상승
    * 시스템 부하감소
* 단점
    * 조회를 제외한 동작이 느려짐
    * 추가 용량 필요
    * 추가 관리 필요

### B-Tree
* 자식노드를 2개 이상 가질 수 있음
* 자식노드를 최대 M개를 가지는 트리를 M차 B-Tree 라고 함
* 노드가 가지는 Key가 1개 이상일 수 있다.


### B+Tree


## 절차적 맵 생성
### WFC 파동붕괴함수
가능성을 판단하여 결정되는 함수
장단점
* 장점
    * 패턴학습
    * 비교적 빠른 속도
* 단점
    * 지역 의존성
    * 불완전 결과

게임 레벨디자인, 맵생성, 모델링, 패턴디자인 등에 사용된다

### 펄린 노이즈
노이즈를 생성하는 함수
* 장점
    * 메모리 효율성
    * 확장성
    * 다차원 적용 가능






<br><br/>
<br><br/>
<br><br/>
<br id='note'></br>
<!-- 노트 -->
# 노트
```
캡스톤 디자인?

```