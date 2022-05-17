
function solution(record) {
    var answer = [];
    const user = {
        id:{},
        message:[]
    };
    const message = [];
    for(var lines of record){
        var line = lines.split(' ');
        var key = line[1];
        if(line[0]=== 'Leave') {
            user.message.push(['님이 나갔습니다.', line[1]]);
            continue;
        }
        else if(line[0]=== 'Enter'){
            user.message.push(['님이 들어왔습니다.', line[1]]);
        }
        user.id[key] = line[2];
    }
    for(var m of user.message){
        answer.push(user.id[m[1]]+m[0]);
    }
    return answer;
}
function manage(command, uid, uname){
    if(command === 'Enter'){}
}