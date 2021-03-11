import java.util.*;

class Solution {
    boolean[] checked;
    int answer = 51;
  
    public int solution(String begin, String target, String[] words) {
        checked=new boolean[words.length];
        dfs(begin, target, 0, words);
        if(answer==51) return 0; //변환이 불가능한 경우
        return answer;
    }
    
    public void dfs(String present, String target, int count, String[] words){
        if(present.equals(target)){ //현재 문자열과 타겟 문자열이 일치하면 dfs 끝
            answer = (answer>count)?count:answer; 
            return;
        }
        
        for(int i=0;i<words.length;i++){
            if(!checked[i] && check(present, words[i])){ //현재 문자열 다음 문자열과 비교(현재 문자열에 해당하는 checked[i]는 항상 false이므로 자기자신은 체크x)
                checked[i]=true;
                dfs(words[i], target, count+1, words);
                checked[i]=false;
            }
        }
        
    }
    
    //한글자만 차이나는지 판단
    public boolean check(String present, String next){
        int count = 0;
        for(int i=0;i<present.length();i++){
            if(present.charAt(i)!=next.charAt(i))
                count++;
        }
        
        return count==1 ? true : false; //한글자 차이일때 true 반환
    }
}
