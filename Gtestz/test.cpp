#include "pch.h"
#include <gtest/gtest.h>
#include<iostream>
#define MAX_SIZE 10

using namespace std;

class Queue {
private:
	int myqueue[MAX_SIZE], front, rear;

public:
	Queue() {
		front = -1;
		rear = -1;
	}

	bool isFull() {
		if (front == 0 && rear == MAX_SIZE - 1) {
			return true;
		}
		return false;
	}

	bool isEmpty() {
		if (front == -1) return true;
		else return false;
	}

	void enQueue(int value) {
		if (isFull()) {
			cout << endl << "Queue is full!!";
		}
		else {
			if (front == -1) front = 0;
			rear++;
			myqueue[rear] = value;
			cout << value << " ";
		}
	}

	int deQueue() {
		int value;
		if (isEmpty()) {
			//cout << "Queue is empty!!" << endl; 
			return(-1);
		}
		else {
			value = myqueue[front];
			if (front >= rear) {      //only one element in queue
				front = -1;
				rear = -1;
			}
			else {
				front++;
			}
			//cout << endl << "Deleted => " << value << " from myqueue";
			return(value);
		}
	}
};

struct QueueTest : public ::testing::Test {
	Queue* q1_;
	Queue* q2_;
	Queue* q3_;
	void SetUp() override {
		cout << "SETUP CALLED" << endl;
		q1_ = new Queue();


		q1_->enQueue(1);
		q1_->enQueue(2);
		q1_->enQueue(1);
		q1_->enQueue(2);
		q1_->enQueue(1);
		q1_->enQueue(2);
		q1_->enQueue(1);
		q1_->enQueue(2);
		q1_->enQueue(1);
		q1_->enQueue(2);
		q1_->enQueue(3);
	}

	//void TearDown() override {
	//	Queue q0_;
	//	Queue q1_;
	//	Queue q2_;
	//}
};






TEST_F(QueueTest, CheckDequeue) {
	ASSERT_TRUE(q1_->deQueue() == 1);

}
TEST_F(QueueTest, CheckDequeue2) {
	ASSERT_TRUE(q1_->deQueue() == 1);
	//ASSERT_TRUE(q1_->deQueue() == 1);

}

//TEST_F(QueueTest, DequeueWorks) {
//	int n = q1_->deQueue();
//	EXPECT_EQ(n, 2);
//
//	n = q1_->deQueue();
//	ASSERT_NE(n, nullptr);
//	EXPECT_EQ(n, 3);
//	
//}




/*T1
int sum(int a, int b) {
	return a + b;
}

int product(int a, int b) {
	return a * b;
}

TEST(MultiplicationWithAddition, SubTestName1) {
	cout << "\nENTER THE NUMBER OF TESTS IN THIS SUB TEST " << endl;
	int num;
	cin >> num;


	for (int i = 0; i < num; i++)
	{
		cout << "\nENTER VALUE OF A,B,N respectively for test "<<i<<" : ";
		int a,b,n;
		cin >>a>>b>>n;
		//USING WITH EXPECT
		EXPECT_EQ(modulo(a, b), n);

	}
	cout << "ALL TEST DONE WITH SUM \n";

	ASSERT_EQ(product(100, 20),2000);

}


TEST(TestName, SubTestName2) {
	//EXPECT_TRUE(sum(100, 200) == 400);

	ASSERT_TRUE(sum(200, 200) == 400);
	ASSERT_TRUE(sum(200, 300) == 500);
	ASSERT_TRUE(sum(200, 000) == 200);
}

*/














/*T2

//TO TEST A FUNCTION IN THE CLASS
class Check {
	int x;
public:
	Check() :x(10) {}
		void setVal(int x2) {
			this->x = x2;

		}
		int getVal() {
			return this->x;

		}

};


//Creating test fixtures

struct TF : public testing::Test {
	Check* c1;
	void SetUp(){
		cout << "SETUP CALLED" << endl;
		c1 = new Check();
	}

	void TearDown() {
		cout << "TEARDOWN CALLED" << endl;
		delete c1;
	}
};
TEST_F(TF, TestSubname1) {

	//Arrange
	//Check* c1 = new Check();

	//Act
	c1->setVal(222);

	//Assert
	ASSERT_EQ(c1->getVal(), 222);

}

TEST_F(TF, TestSubname2) {

	//Arrange--NO NEED TO WRITE
	//Check* c1 = new Check();

	//Act
	c1->setVal(333);

	//Assert
	ASSERT_EQ(c1->getVal(), 333);


}




















//TEST(TestCaseName, TestSubname1) {
//
//	//Arrange
//	Check* c1 = new Check();
//
//	//Act
//	c1->setVal(222);
//
//	//Assert
//	ASSERT_EQ(c1->getVal(), 222);
//
//}
//
//TEST(TestCaseName, TestSubname2) {
//
//	//Arrange
//	Check* c1 = new Check();
//
//	//Act
//	c1->setVal(333);
//
//	//Assert
//	ASSERT_EQ(c1->getVal(), 333);
//
//
//}





//TEST(TestCaseName, TestName) {
//  //EXPECT_EQ(1, 1);
//  //EXPECT_TRUE(true);
//	cout << "assert" << endl;
//	ASSERT_TRUE(5 == 5);
//	//two ways to write assert above is one way
//	cout << "expect" << endl;
//	//EXPECT_FALSE(100 == 101);
//	//ASSERT_TRUE(100 == 100);
//	//EXPECT_TRUE(100 == 101);
//}


*/