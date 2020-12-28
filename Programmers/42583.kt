import java.util.*

class Solution {
    fun solution(bridge_length: Int, weight: Int, truck_weights: IntArray): Int {
        var answer = 0
        var currentWeight = 0
        var idx = 0
        var finishNum = 0
        var q = LinkedList<Truck>()
        var tempq = LinkedList<Truck>()
        while(finishNum < truck_weights.size){
            var flag = false
            if((idx < truck_weights.size) && (currentWeight + truck_weights[idx] <= weight)){
                currentWeight += truck_weights[idx]
                q.add(Truck(truck_weights[idx], 0))
                idx++
                flag = true
            }
            while(!q.isEmpty()){
                var pair = q.peek()
                if(pair.pos == bridge_length){
                    currentWeight -= pair.weight
                    finishNum++
                    if((idx < truck_weights.size) && (currentWeight + truck_weights[idx] <= weight)){
                        if(!flag){
                            currentWeight += truck_weights[idx]
                            q.add(Truck(truck_weights[idx], 0))
                            idx++
                        }
                    }
                }else {
                    pair.pos++
                    tempq.add(pair)   
                }
                q.poll()
            }
            while(!tempq.isEmpty()){
                q.add(tempq.peek())
                tempq.poll()
            }
            answer++
        }
        return answer
    }
    
    data class Truck(var weight : Int, var pos : Int)
}