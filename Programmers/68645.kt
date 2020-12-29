class Solution {
    fun solution(n: Int): IntArray {
        val max = (n*(n+1))/2
        var answer = IntArray(max)
        var arr = Array(n) {IntArray(n)}
        var type = 0
        var cx = 0
        var cy = 0
        var idx = 1
        
        for(i in n downTo 1){
            if(type == 0) { // 위 -> 아래
                for(j in 1..i){
                    arr[cx++][cy] = idx++
                }
                cx--
                cy++
            } else if(type == 1) { // 왼 -> 오
                for(j in 1..i){
                    arr[cx][cy++] = idx++
                }
                cy-=2
                cx--
            } else { // 오-> 위
                for(j in 1..i){
                    arr[cx--][cy--] = idx++
                }
                cx+=2
                cy++
            }
            type++
            if(type == 3) type = 0
        }
        
        idx = 0
        for(i in 0..n-1){
            for(j in 0..n-1){
                if(arr[i][j] != 0) {
                    answer[idx++] = arr[i][j]
                }
            }
        }
        return answer
    }
}