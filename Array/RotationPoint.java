/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package array;

/**
 *
 * @author lavanyanadikuda
 */
public class RotationPoint {


    int rotationPoint(String[] words){

        return search(words, 0, words.length-1);


    }

    int search(String[] words, int left, int right){
        if(words == null || words.length == 0)
            return -1;

        if(left == right) {
            return left;
        }

        int mid = (left + right)/2;

        // check if middle is the element which is rotation point
        if(words[mid-1].charAt(0) > words[mid].charAt(0))
            return mid;

        if(words[left].charAt(0) <= words[mid].charAt(0))
            return search(words, left, mid-1);

        if(words[mid].charAt(0) >= words[right].charAt(0))
            return search(words, mid+1, right);

        return -1;

    }


    int findRotationPoint(String[] words){
        int min = 0;
        int max = words.length -1;
        String firstword = words[0];

        // modified binary search algorithm
        while(min < max){
            int mid = (min+max)/2;

            // if mid word first index is less than first word first index,
            // the rotation point is in first half of array
            if(words[mid].charAt(0) < firstword.charAt(0)){
                max = mid;
            } else {
                min = mid;
            }

            // the min reaches max we have found our index
            if(min+1 == max)
                return max;
        }
        return min;
    }

    public static void main(String[] args) {
        String[] words = new String[]{
        "babka",
        "banoffee",
        "engender",
        "karpatka",
        "othellolagkage",
        "ptolemaic",
        "retrograde",
        "supplant",
        "undulate",
        "xenoepist",
        "asymptote",  // <-- rotates here!

        };
        RotationPoint rp = new RotationPoint();
        int rp1 = rp.findRotationPoint(words);
        System.out.println(rp1);
    }



}
