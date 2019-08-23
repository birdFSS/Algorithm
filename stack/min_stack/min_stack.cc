#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

class Min_stack{
public:
    void push(int value) {
        if(0 == m_min.size() || m_min.top() > value)
        {
            m_min.push(value);

        }else{
            m_min.push(m_min.top());
        }
        m_st.push(value);
    }
    void pop() {
        assert(m_st.size() > 0 && m_min.size() > 0);

        m_st.pop();
        m_min.pop();

    }
    int top() {
        assert(m_st.size() > 0);
        return m_st.top();

    }
    int min() {
        assert(m_min.size() > 0);

        return m_min.top();
    }

private:
    std::stack<int> m_st;
    std::stack<int> m_min;

};

int main()
{
    Min_stack mst;
    mst.push(2);
    mst.push(9);
    cout << mst.min() << endl;
    return 0;
}

