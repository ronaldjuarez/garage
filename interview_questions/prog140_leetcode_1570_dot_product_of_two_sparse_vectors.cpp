#include <iostream>
#include <vector>


class SparseVector
{
public:
    struct Node
    {
        int idx;
        int val;
        Node* next;  
        Node(int idx, int val): idx(idx), val(val), next(nullptr) {}
    };

    Node* m_sparseVector;

    SparseVector(std::vector<int>& nums)
    {
        m_sparseVector = nullptr;
        Node* currPtr = nullptr;
        for (size_t idx = 0 ; idx < nums.size(); idx++)
        {
            if (nums[idx] != 0)
            {
                if (m_sparseVector)
                {
                    currPtr->next = new Node(idx, nums[idx]);
                    currPtr = currPtr->next;
                }
                else
                {
                    m_sparseVector = new Node(idx,nums[idx]);
                    currPtr = m_sparseVector;
                }
            }
        }
    }

    int dotProduct(SparseVector& vec)
    {
        Node* ptr1 = m_sparseVector;
        Node* ptr2 = vec.m_sparseVector;

        int resultSum = 0;

        while (ptr1 != nullptr && ptr2 != nullptr)
        {
            if (ptr1->idx == ptr2->idx)
            {
                resultSum += ptr1->val * ptr2->val;
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else if (ptr1->idx < ptr2->idx)
            {
                ptr1 = ptr1->next;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        return resultSum;
    }
};

int main()
{
    std::vector<int> nums1{1,0,0,2,3};
    std::vector<int> nums2{0,3,0,4,0};

    SparseVector v1(nums1);
    SparseVector v2(nums2);

    auto sum = v1.dotProduct(v2);
    std::cout << "=== TEST CASE 1 ==== " << std::endl;
    std::cout << sum << std::endl;

    std::vector<int> nums3{0,1,0,0,2,0,0};
    std::vector<int> nums4{1,0,0,0,3,0,4};

    SparseVector v3(nums3);
    SparseVector v4(nums4);

    auto sum2 = v3.dotProduct(v4);
    
    std::cout << "=== TEST CASE 2 ==== " << std::endl;
    std::cout << sum2 << std::endl;

    return 0;
}