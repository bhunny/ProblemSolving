function solution(board, moves) {
    var answer = 0;
    //moves[0] -> 첫번째 이동
    // 각 칸의 제일 위에서 부터 빠져나가야 한다.
    
    
    //위치 i-1이 board[n][i]와 매칭된다.
    var basket = [];
    for(i of moves){
        for(j of board){
            if(basket && basket[basket.length-1]===j[i-1]){
                //console.log(j[i-1]);
                answer+=2;
                
                basket.push(j[i-1]);
                //console.log(j," "+i+'번째');
                
                //console.log('same basket: ',basket);
                basket.pop();
                basket.pop();
                
                //console.log('pop basket: ',basket);
                j[i-1] = 0;
                break;
            }
            else if(j[i-1]) {
                //console.log(j," "+i+'번째');
                basket.push(j[i-1]);
                //console.log(basket);
                j[i-1] = 0;
                break;
            }
            
        }
    }
    //console.log(basket);
    return answer;
    
    /*
    00000
    00103
    02501
    42442
    35131
    
    15351214
    
    */
}