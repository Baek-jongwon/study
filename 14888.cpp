#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	int op_max[4];
	int op_min[4];
	int max;
	int min;

	for(int j =0; j<n; j++)
	{
		
		cin >> arr[j];
		
	}
	for (int i = 0; i < 4; i++)
	{
		int num;
		cin >> num;
		op_max[i] = num;
		op_min[i] = num;

		
	}
	//최대값
	for (int k = 0; k <n-1; k++)
	{
		if (arr[k] != 0 && arr[k+1] !=0)
		{
			if (op_max[1] > 0)
			{
				if (k == 0)
				{
					max = arr[k] - arr[k + 1];
				}
				else max -= arr[k + 1];
				op_max[1]--;
			}
			else 
			{
				if (op_max[3] > 0)
				{
					if (k == 0)
					{
						max = arr[k] / arr[k + 1];
					}
					else max /= arr[k + 1];
					op_max[3]--;
				}
				else 
				{
					if (op_max[0] > 0)
					{
						if (k == 0)
						{
							max = arr[k] + arr[k + 1];
						}
						else max += arr[k + 1];
						op_max[0]--;
					}
					else 
					{
						if (op_max[2] > 0)
						{
							if (k == 0)
							{
								max = arr[k] * arr[k + 1];
							}
							else max *= arr[k + 1];
							op_max[2]--;
						}
					}
				}
			}
			
		}
	}
	cout << max << "\n";
	//최소값
	
	for (int k = 0; k < n - 1; k++)
	{
		if (arr[k] != 0 && arr[k + 1] != 0)
		{
			if (op_min[1] > 0)
			{
				if (op_min[0] > 0)
				{
					if (k == 0)
					{
						min = arr[k] + arr[k + 1];
					}
					else min += arr[k + 1];
					op_min[0]--;
				}
				else
				{
					if (op_min[3] > 0)
					{
						if (k == 0)
						{
							min = arr[k] / arr[k + 1];
						}
						else min /= arr[k + 1];
						op_min[3]--;
					}
					else
					{
						if (op_min[1] > 0)
						{
							if (k == 0)
							{
								min = arr[k] - arr[k + 1];
							}
							else min -= arr[k + 1];
							op_min[1]--;
						}
						else
						{
							if (op_min[2] > 0)
							{
								if (k == 0)
								{
									min = arr[k] * arr[k + 1];
								}
								else min *= arr[k + 1];
								op_min[2]--;
							}
						}
					}
				}

			}
			else {
				if (op_min[3] > 0)
				{
					if (op_min[0] > 0)
					{
						if (k == 0)
						{
							min = arr[k] + arr[k + 1];
						}
						else min += arr[k + 1];
						op_min[0]--;
					}
					else {
						if (op_min[3] > 0)
						{
							if (k == 0)
							{
								min = arr[k] / arr[k + 1];
							}
							else min /= arr[k + 1];
							op_min[3]--;
						}
						else {
							if (op_min[2] > 0)
							{
								if (k == 0)
								{
									min = arr[k] * arr[k + 1];
								}
								else min *= arr[k + 1];
								op_min[2]--;
							}

						}
					}

				}
				else
				{
					if (op_min[2] > 0)
					{
						if (k == 0)
						{
							min = arr[k] * arr[k + 1];
						}
						else min *= arr[k + 1];
						op_min[2]--;
					}
					
					else {
						if (op_min[0] > 0)
						{
							if (k == 0)
							{
								min = arr[k] + arr[k + 1];
							}
							else min += arr[k + 1];
							op_min[0]--;
						}
					}
				}
			}
			

		}
	}
	cout << min << "\n";


}