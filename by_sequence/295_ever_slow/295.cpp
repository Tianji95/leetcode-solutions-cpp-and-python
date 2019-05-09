class MedianFinder {
public:
    /** initialize your data structure here. */
    std::priority_queue<int> Qsmall;
    std::priority_queue<int> Qlarge;
    int count;
    
    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        Qsmall.push(num);
        Qlarge.push(-Qsmall.top());
        Qsmall.pop();
        if(Qsmall.size() < Qlarge.size()){
            Qsmall.push(-Qlarge.top());
            Qlarge.pop();
        }
        count++;
    }
    
    double findMedian() {
        if(count % 2 == 1){
            return Qsmall.top();
        }
        else{
            return (Qsmall.top() - Qlarge.top()) / 2.0;
        }
    }
};