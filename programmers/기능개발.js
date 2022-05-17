function solution(progresses, speeds) {
    var answer = [];
    let release = [];
    progresses.forEach((p, index) => {
        release.push(Math.ceil((100-p)/speeds[index]));
        
    });
    console.log(release);
    let value = release[0];
    let count = 0;
    release.forEach((v,i) => {
        if(value<v){
            value = v;
            answer.push(count);
            count = 1;
        }
        else{
            count ++; 
        }  
        if(i === release.length-1){
            console.log(count);
            answer.push(count);
        }        
    })
    return answer;
}