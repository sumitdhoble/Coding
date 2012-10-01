#include<iostream>
#include<stdlib.h>
using namespace std;

class Flight{
	public:
		int source;
		int destination;
		int departureTime;
		int arrivalTime;

};

class TestCase{
	public :
		int numberOfFlights;
		Flight *flights;
		int sourceCity;
		int departureTime;
		int destinationCity;
		int arrivalTime;
		int result;
		int maxTime;
		int minTime;
		int maxAirport;
		int minAirport;
};

class AirportScheduler {

public:
	int i, j, numberOfTestCases;
	TestCase *testCase;

	AirportScheduler();

	virtual ~AirportScheduler();

	void ReadInput();

	void SanityCheck();

	void PrintInput();

	int BinarySearch(int i, int destination, int arrivalTime);

	void Solve();

	int minimumNumberOfFlights(int i, int source, int destination, int departureTime, int arrivalTime);
};

AirportScheduler::AirportScheduler() {
	i = 0; j = 0; numberOfTestCases = 0;
}

AirportScheduler::~AirportScheduler() {
}

void AirportScheduler::ReadInput(){
	cin >> numberOfTestCases;
	testCase = new TestCase[numberOfTestCases+1];

	for(i = 1; i <= numberOfTestCases; i++){
		cin >> testCase[i].numberOfFlights;
		testCase[i].flights = new Flight[testCase[i].numberOfFlights+1];

		for(j = 1; j <= testCase[i].numberOfFlights; j++){
			cin >> testCase[i].flights[j].source;
			cin >> testCase[i].flights[j].departureTime;
			cin >> testCase[i].flights[j].destination;
			cin >> testCase[i].flights[j].arrivalTime;
		}

		cin >> testCase[i].sourceCity;
		cin >> testCase[i].departureTime;
		cin >> testCase[i].destinationCity;
		cin >> testCase[i].arrivalTime;
	}

}

void AirportScheduler::SanityCheck(){
	for(i = 1; i <= numberOfTestCases; i++){
			testCase[i].result = 0;
			for(j = 1; j <= testCase[i].numberOfFlights; j++){
				if(testCase[i].flights[j].source > testCase[i].maxAirport)
					testCase[i].maxAirport = testCase[i].flights[j].source;
				if(testCase[i].flights[j].destination > testCase[i].maxAirport)
					testCase[i].maxAirport = testCase[i].flights[j].destination;
				if(testCase[i].flights[j].source < testCase[i].minAirport)
					testCase[i].minAirport = testCase[i].flights[j].source;
				if(testCase[i].flights[j].destination < testCase[i].minAirport)
					testCase[i].minAirport = testCase[i].flights[j].destination;
				if(testCase[i].flights[j].arrivalTime > testCase[i].maxTime)
					testCase[i].maxTime = testCase[i].flights[j].arrivalTime;
				if(testCase[i].flights[j].departureTime > testCase[i].maxTime)
					testCase[i].maxTime = testCase[i].flights[j].departureTime;
				if(testCase[i].flights[j].arrivalTime < testCase[i].minTime)
					testCase[i].minTime = testCase[i].flights[j].arrivalTime;
				if(testCase[i].flights[j].departureTime < testCase[i].minTime)
					testCase[i].minTime = testCase[i].flights[j].departureTime;
			}

			if(testCase[i].arrivalTime < testCase[i].minTime)
				testCase[i].result = -1;
			if(testCase[i].departureTime > testCase[i].maxTime)
				testCase[i].result = -1;
			if(testCase[i].destinationCity < testCase[i].minAirport || testCase[i].destinationCity > testCase[i].maxAirport)
				testCase[i].result = -1;
			if(testCase[i].arrivalTime < testCase[i].minTime)
				testCase[i].result = -1;
	}
}

void AirportScheduler::PrintInput(){
	cout << endl;
	for(i = 1; i <= numberOfTestCases; i++){
		cout << testCase[i].numberOfFlights << endl;
		for(j = 1; j <= testCase[i].numberOfFlights; j++){
			cout << testCase[i].flights[j].source << " ";
			cout << testCase[i].flights[j].departureTime << " ";
			cout << testCase[i].flights[j].destination << " ";
			cout << testCase[i].flights[j].arrivalTime << endl;
		}

		cout << testCase[i].sourceCity << " ";
		cout << testCase[i].departureTime << " ";
		cout << testCase[i].destinationCity << " ";
		cout << testCase[i].arrivalTime << endl;
	}
}

int FlightCompare(const void * a, const void * b){
	const Flight *f = (const Flight *)a;
	const Flight *g = (const Flight *)b;

	if(f->destination > g->destination)
		return 1;
	else if(f->destination == g->destination && f->arrivalTime > g->arrivalTime)
		return 1;
	else if(f->destination == g->destination && f->arrivalTime == g->arrivalTime && f->departureTime > g->departureTime)
		return 1;
	else
		return -1;
}

int AirportScheduler::BinarySearch(int i, int destination, int arrivalTime){
	int low = 1, mid = 1, high = testCase[i].numberOfFlights, index = 0;

	if(testCase[i].numberOfFlights == 1)
		mid = 1;
	else
		mid = testCase[i].numberOfFlights/2;

	while(true){
		//cout << "low = " << low << " high = " << high << " mid = " << mid << endl;
		if(testCase[i].flights[mid].destination == destination && testCase[i].flights[mid].arrivalTime <= arrivalTime){
			index = mid;
			break;
		}
		else if(testCase[i].flights[mid].destination >= destination){
			high = mid-1;
		}
		else {
			low = mid+1;
		}
		mid = low + (high-low)/2;
		if(high == low && !(testCase[i].flights[mid].destination == destination && testCase[i].flights[mid].arrivalTime <= arrivalTime)){
			index = -1;
			break;
		}else if(high < low){
			index = -1;
			break;
		}

	}

	return index;
}

void AirportScheduler::Solve(){
	int source, destination, departureTime, arrivalTime, index = 0, count = 0;
	int j = 1;

	for(i = 1; i <= numberOfTestCases; i++){

		count = 0;

		if(testCase[i].result == -1){
			cout << "No" << endl;
			continue;
		}

		qsort(testCase[i].flights+1, testCase[i].numberOfFlights, sizeof(Flight), FlightCompare);

		//for(j = 1; j <= testCase[i].numberOfFlights; j++)
		//	cout << testCase[i].flights[j].source << " " << testCase[i].flights[j].departureTime << " " << testCase[i].flights[j].destination << " " << testCase[i].flights[j].arrivalTime << endl;

		source = testCase[i].sourceCity;
		destination = testCase[i].destinationCity;
		departureTime = testCase[i].departureTime;
		arrivalTime = testCase[i].arrivalTime;

		do{
			index = BinarySearch(i, destination, arrivalTime);
			//cout << "destination = " << destination << " arrivalTime = " << arrivalTime << " index = " << index << " count = " << count << endl;
			if(index < 0){
				testCase[i].result = -1;
				break;
			}
			else if(testCase[i].sourceCity == testCase[i].flights[index].source && testCase[i].departureTime <= testCase[i].flights[index].departureTime){
				count++;
				testCase[i].result = count;
				break;
			}
			else if(testCase[i].sourceCity == testCase[i].flights[index].source && testCase[i].departureTime > testCase[i].flights[index].departureTime){
				testCase[i].result = -1;
				break;
			}
			else{
				count++;
				destination = testCase[i].flights[index].source;
				arrivalTime = testCase[i].flights[index].departureTime;
			}
		}while(true);

		if(testCase[i].result == -1)
			cout << "No" << endl;
		else if(testCase[i].result > 0)
			cout << "Yes " << testCase[i].result << endl;
	}

}

// recursive solution : time limit exceeds
int AirportScheduler::minimumNumberOfFlights(int i, int source, int destination, int departureTime, int arrivalTime){
	int minFlights = testCase[i].numberOfFlights;
	int j = 0;
	int tempResult = 0;
	int flag = -1;

	for(j = 1; j <= testCase[i].numberOfFlights ; j++){
		if(testCase[i].flights[j].source == source && testCase[i].flights[j].destination == destination && testCase[i].flights[j].arrivalTime <= arrivalTime && testCase[i].flights[j].departureTime >= departureTime)
			return 1;
	}

	for(j = 1; j <= testCase[i].numberOfFlights ; j++){
		if(testCase[i].flights[j].destination == destination && testCase[i].flights[j].arrivalTime <= arrivalTime && testCase[i].flights[j].departureTime >= departureTime){
			tempResult = minimumNumberOfFlights(i, source, testCase[i].flights[j].source, departureTime, testCase[i].flights[j].departureTime);
			if(tempResult != -1 && minFlights > tempResult+1)
				minFlights = tempResult+1;
			flag = 1;
		}
	}

	if(flag == -1)
		minFlights = -1;

	return minFlights;
}


int main(){
	AirportScheduler scheduler;
	scheduler.ReadInput();
	//scheduler.SanityCheck();
	//scheduler.PrintInput();
	scheduler.Solve();
}

