#include <iostream>
using namespace std;

void write(int* data, int count, bool flag = false, bool flag2 = false)
{
	int last = 15;
	int twoPrevious = 15;
	int total = 0;
	int current = -1;
	int temp = 100;
	cout << "\n\n" << "Head Movement" << "\t\t\t" << "Tracks Traversed" << "\t" << "\n";
	int temp3 = -1;
	if(flag2)
	{
		for(int i = 0; i< count; i++)
		{
			for(int j = 0; j < count-1; j++)
			{
				if(data[j] > data[j+1])
				{
					int temp4 = data[j+1];
					data[j+1] = data[j];
					data[j] = temp4;
				}
			}
		}
	}
	for(int i = 0; i < count; i++)
	{
		if(!flag)
		{
			current = data[i];
			temp = 0;
			if(current > last)
			temp = current-last;
			else
			temp = last-current;
			total += temp;
		}
		else
		{

			temp = 1000;
			for(int j = 0; j < count; j++)
			{
				if(data[j] != last && data[j] != twoPrevious)
				{
					int temp2 = -1;
					if(last < data[j])
						temp2 = data[j] - last;
					else
						temp2 = last - data[j];
					if(temp2 < temp)
					{
						temp3 = j;
						temp = temp2;
					}
				}
			}
			current = data[temp3];
			data[temp3] = -1000;
			total += temp;
		}
		cout << "Tracks " << last << " - " << current << "\t\t\t" << temp << "\n";
		last = current;
	}
	cout << "\n" << "Total Tracks Traversed" << "\t\t" << total << "\n\n";
}
int main()
{
	int start = 15;
	int fcfs[100];
	int sstf[100];
	int sloe[100];
	int count = 0;
	int x = 0;
	cin >> x;
	while(x >= 0)
	{
		fcfs[count] = x;
		sstf[count] = x;
		sloe[count] = x;
		count++;
		cin >> x;
	}
	cout << "First Come First Served\n";
	write(fcfs,count);
	cout << "Shortest Seek Time First\n";
	write(sstf,count,true);
	cout << "Scan-Look or Elevator\n";
	write(sloe,count,false,true);
	cin >> x;
	return 0;
}
