function solution(new_id) {
    let answer = '';
    //1. 대문자 -> 소문자
    answer = new_id.toLowerCase();
    
    //2. 소문자, 숫자, 빼기, 밑줄, 마침표를 제외한 모든 문자 제거
    //\w: 알파벳,숫자,밑줄
    
    // answer = answer.match(/\w|\.|\-/g);
    // //match()는 배열로 출력 -> join()으로 문자열로 변환
    // answer = answer.join('');
    
    answer = answer.replace(/[^\w-.]/g,'');

    //3. [.] 가 2개 이상일 때, [.]로 치환
    //replace(정규표현식,대체문자열) : 해당하는 문자열을 대체문자열로 변환
    answer = answer.replace(/\.{2,}/g,'.');
    
    //4. 
    // 첫번째 문자열과 마지막 문자열이 '.' 이라면 제거
    // ^문자열 : 문자열~로 시작
    // 문자열$ : ~문자열로 끝남
    answer = answer.replace(/^\.|\.$/g,"");
    
    //5. id가 빈문자열이면 a 넣어준다.
    // if(answer === '') answer='a';
    answer = answer.replace(/^$/,'a');
    //6. id의 길이가 16자 이상이라면 첫 15개 제외 모두 제거, 마지막 문자열이 '.'이라면 제거
    answer = answer.slice(0,15).replace(/\.$/g,"");
    
    //7. id의 길이가 2자 이하라면 마지막 문자를 id의 길이가 3이 될 때까지 반복해서 끝에 붙임
    //  while(answer.length<3){
    //     answer = answer+answer[answer.length-1];
    // }

    return answer.padEnd(3,answer[answer.length-1]);

}