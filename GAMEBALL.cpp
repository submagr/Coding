#include<stdio.h>
#include<vector>
using namespace std;

bool debug = false;
bool ar[10][10];
int n, m;

typedef struct node{
    int x1;
    int y1;
    int x2;
    int y2;
}node;

vector<node> myMoves;
void printAr(){
    for(int i = 0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ar[i][j])
                printf("* ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

void move(int type, int x1, int y1, int x2, int y2){
    if(type == 1){ // Move the ball to adjacent empty cell
        ar[x1][y1] = false;
        ar[x2][y2] = true;
    }else if(type == 2){
        if(x1 == x2){ // Vertical
            ar[x1][y1] = false;
            ar[x1][(y1+y2)/2] = false;
            ar[x2][y2] = true;
        }else if(y1 == y2){ // Horizontal
            ar[x1][y1] = false;
            ar[(x1+x2)/2][y1] = false;
            ar[x2][y2] = true;
        }
    }
    if(debug){
        printf("-----------------");
        printf("Move %d: %d %d %d %d\n", type, x1, y1, x2, y2);
        printAr();
    }
    node myNode;
    myNode.x1 = x1; 
    myNode.y1 = y1; 
    myNode.x2 = x2; 
    myNode.y2 = y2; 
    myMoves.push_back(myNode);
}

void customPrint(){
    printf("%ld\n", myMoves.size());
    if(myMoves.size()>0){
        for(long i=0; i<myMoves.size(); i++){
            printf("%d %d %d %d\n", myMoves[i].x1+1, myMoves[i].y1+1, myMoves[i].x2+1, myMoves[i].y2+1);
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        int doti, dotj;
        for(int i=0; i<n; i++){
            char temp;
            scanf("%c", &temp);
            for(int j=0; j<m; j++){
                char ch;
                scanf("%c", &ch);
                if(ch=='*'){
                    ar[i][j] = true;
                }else if(ch == '.'){
                    ar[i][j] = false;
                    doti = i;
                    dotj = j;
                }
            }
        }
        if(debug){
            printf("--------\n");
            printf("initial array\n");
            printAr();
        }
        // Set initial universal location of dot: bottom rightmost
        // - Move the dot to lowest row
        while(doti != n-1){
            move(1, doti+1, dotj, doti, dotj);
            doti = doti+1;
        }
        // - Move the dot to rightmost column
        while(dotj != m-1){
            move(1, doti, dotj+1, doti, dotj);
            dotj = dotj+1;
        }

        if(n>2 and m>2){
            for(int i=n-1; i>=0; i--){
                // Make all x in i^th row ., except the leftmost x
                int y1=m-3;
                while(y1>=0){
                    int y2 = y1+2;
                    move(2, i, y1, i, y2);
                    move(1, i,y2, i, y2-1);
                    move(1, i,y2-1, i, y2-2);
                    y1 = y1-1;
                } 
                // At end of this loop i^(th) row contains x only at leftmost position
                if(i!=0){
                    // Move one dot to the upper row at rightmost position. Also settle the resulting x in current row
                    move(1, i-1, m-1, i, m-1);
                    y1 = m-1 ;
                    while(y1>1){
                        move(1, i, y1, i, y1-1);
                        y1-=1;
                    } // x x . . . 
                    move(2, i, 0, i, 2);
                    move(1, i, 2, i, 1);
                    move(1, i, 1, i, 0);
                }
            } 
            // x . . . .
            // x . . . .
            // x . . . .
            move(1, n-1, 0, n-1, 1);
            // x . . . .
            // x . . . .
            // x . . . .
            // . x . . .
            int x1 = n-3;
            while(x1>=0){
                int x2 = x1+2;
                move(2, x1, 0, x1+2, 0);
                move(1, x1+2, 0, x1+1, 0);
                move(1, x1+1, 0, x1, 0);
                x1-=1;
            } 
            // x . . . .
            // . . . . .
            // . . . . .
            // . x . . .
            x1 = 0; 
            while(x1!=n-1){
                move(1, x1, 0, x1+1, 0);
                x1+=1;
            }
            move(2, n-1,0, n-1, 2);
        } 
        else if(n>2 and m==2){
            int x1 = n-3; 
            int y1 = 1;
            while(x1>=0){
                move(2, x1,y1, x1+2, y1);
                move(1, x1+2, y1, x1+1, y1);
                move(1, x1+1, y1, x1, y1);
                x1-=1;
            }
            // x x  
            // x .
            // x .
            // x .
            move(1, n-1, 0, n-1, 1);
            // x x  
            // x .
            // x .
            // . x 
            x1 = n-3; 
            y1 = 0;
            while(x1>=0){
                move(2, x1,y1, x1+2, y1);
                move(1, x1+2, y1, x1+1, y1);
                move(1, x1+1, y1, x1, y1);
                x1-=1;
            }
            // x x 
            // . .
            // . .
            // . x 
            x1 = n-1;
            while(x1>1){
                move(1, x1, 1, x1-1, 1);
                x1-=1;
            }
            // x x 
            // . x 
            // . .
            // . .
            // . . 
            move(2, 0, 1, 2, 1);
            move(1, 2,1,1,1);
            move(1, 1,1,1,0);
            move(2, 0, 0, 2,0);
        }else if(n>2 and m==1){
            int x1 = n-3; 
            int y1 = 0;
            while(x1>=0){
                move(2, x1,y1, x1+2, y1);
                if(x1!=0){
                    move(1, x1+2, y1, x1+1, y1);
                    move(1, x1+1, y1, x1, y1);
                }
                x1-=1;
            }
        }
        else if(n==2 and m>2){
            // x x x x x  
            // x x x x .
            int x1 = 1;
            int y1 = m-3;
            while(y1>=0){
                move(2, x1, y1, x1, y1+2);
                move(1, x1, y1+2, x1, y1+1);
                move(1, x1, y1+1, x1, y1);
                y1-=1;
            }
            // x x x x x  
            // x . . . .
            move(1, 0, m-1, 1, m-1);
            // x x x x .  
            // x . . . x 
            x1 = 0;
            y1 = m-3;
            while(y1>=0){
                move(2, x1, y1, x1, y1+2);
                move(1, x1, y1+2, x1, y1+1);
                move(1, x1, y1+1, x1, y1);
                y1-=1;
            }
            // x . . . .  
            // x . . . x 
            y1 = m-1;
            while(y1>1){
                move(1, 1, y1, 1, y1-1);
                y1-=1;
            }
            // x . . . .  
            // x x . . .
            move(2, 1, 0, 1, 2) ;
            move(1, 1,2, 1,1);
            move(1,1,1,0,1);
            move(2,0,0,0,2);
        }else if(n==1 and m>2){
            // x x x x .
            int x1 = 0;
            int y1 = m-3;
            while(y1>=0){
                move(2, x1, y1, x1, y1+2);
                if(y1!=0){
                    move(1, x1, y1+2, x1, y1+1);
                    move(1, x1, y1+1, x1, y1);
                }
                y1-=1;
            }
            // x . . . .
        }    
        if((n == 2 and m==2) or (n==1 and m==1)){
            printf("-1\n");
        }else if((n==2 and m==1) or (n==1 and m==2)){
            printf("0\n");
        }else {
            customPrint();
        }
        myMoves.clear();
    }
    return 0;
}
