function solution(board, moves) {
    var answer = 0;
    //moves[0] -> 첫번째 이동
    // 각 칸의 제일 위에서 부터 빠져나가야 한다.
    
    
    //위치 i-1이 board[n][i]와 매칭된다.
    var basket = [];
    //i(선택할위치)를 선택한 뒤, 보드 배열을 탐색한다.
    for(i of moves){
        for(j of board){
            //바스켓의 제일 마지막 원소와 비교해서 같으면 마지막 원소 빼내고
            //해당 위치 0으로 초기화
            //answer +2
            if(basket && basket[basket.length-1]===j[i-1]){
                basket.pop();
                j[i-1] = 0;
                answer+=2;
                break;
            }
            //해당 위치에 원소가 존재하면 바스켓에 넣고 해당 위치 0
            else if(j[i-1]) {
                basket.push(j[i-1]);
                j[i-1] = 0;
                break;
            }
            
        }
    }
    return answer;