class Solution
{
public:
	bool validUtf8(vector<int>& data)
	{

		int len = data.size();
		bool isFirst = true;
		int idx = 0;
		int count = 0;

		while (idx < len)
		{
			if (isFirst)
			{
				count = 0;
				for (int i = 0; i < 4; i++)
				{
					if (data[idx] & (1 << (7 - i)))
					{
						count++;
					}
					else
					{
						break;
					}
				}
				if ((data[idx] & (1 << (7 - count)) )!= 0)
				{
					return false;
				}
                if(count == 1){
                    return false;
                }
				if (count != 0)
				{
					count--;
					isFirst = false;
				}
			}
			else
			{
				count--;
				if (!count)
				{
					isFirst = true;
				}
				if ((data[idx] & (1 << 7)) != 128)
				{
					return false;
				}
				if (data[idx] & (1 << 6))
				{
					return false;
				}
			}
			idx++;
		}
        if(count !=0 ){
            return false;
        }
		return true;

	}
};