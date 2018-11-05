class Solution(object):
    def findMedianSortedArrays(self, numsA, numsB):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        lenA = len(numsA)
        lenB = len(numsB)
        # 假设A长度比B小，否则后面会减出负数
        if lenA > lenB:
            numsA,numsB = numsB,numsA
            lenA, lenB = lenB, lenA
        if lenA is 0:
            middle = numsB[int((lenB-1)/2)]
            if lenB % 2 is 1:
                return middle
            else:
                return (middle+numsB[int((lenB-1)/2)+1]) / 2.0
        
        amin = 0
        amax = lenA
        lenHalf = (lenA+lenB+1) / 2
        while amin <= amax:
            i = (amin+amax) / 2
            j = lenHalf - i
            if i < lenA and numsB[j-1] > numsA[i]:
                #i 太小
                amin = i + 1
            elif i > 0 and numsB[j] < numsA[i-1]:
                #i 太大
                amax = i - 1
            else:
                if i is 0:
                    leftPart = numsB[j-1]
                elif j is 0:
                    leftPart = numsA[i-1]
                else:
                    leftPart = max(numsA[i-1], numsB[j-1])
                print(leftPart)
                if i is lenA:
                    rightPart = numsB[j]
                elif j is lenB:
                    rightPart = numsA[i]
                else:
                    rightPart = min(numsA[i], numsB[j])
                print(rightPart)
                if (lenA + lenB) % 2 is 0:
                    return (leftPart+rightPart)/ 2.0
                else:
                    return leftPart
            
                
            