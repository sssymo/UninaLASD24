#include <iostream>
// #include "..."
#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/dictionary.hpp"
#include "../container/traversable.hpp"
#include "../container/linear.hpp"

#include "../vector/vector.hpp"
#include "../list/list.hpp"

#include "../queue/queue.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../stack/stack.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"

#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"

#include "../bst/bst.hpp"
#include "../hashtable/hashtable.hpp"
#include "../hashtable/clsadr/htclsadr.hpp"
#include "../hashtable/opnadr/htopnadr.hpp"
#include "./test.hpp"
/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void mytest() {
  // ...
cout << endl << "Welcome To My Tests:" << endl<<endl;
cout << endl << " - - -  Vector Tests  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" <<endl<< endl;
    cout << endl << " - - -  Vector Tests with integers - - - " <<endl<< endl;
lasd::SortableVector<int> vect;
cout << "vect should be empty: " << vect.Empty() << endl;
cout << "vect size should be 0: " << vect.Size() << endl;
vect.Resize(5);
cout << "vect size should be 5 after resize(5) : " << vect.Size() << endl;
cout << "First element of vector (0): " << vect.Front() << endl;
cout << "Last element of vect (0): " << vect.Back() << endl;
lasd::SortableVector<int> vectCopy(vect);
cout << "vectCopy size should be 5: " << vectCopy.Size() << endl;
lasd::SortableVector<int> vectMove(move(vectCopy));
cout << "vectMove size should be 5: " << vectMove.Size() << endl;
cout << "Creating a vector for the fold and map test:" << endl;
lasd::Vector<int> vectorForTest(5);
cout << "Inserting the following elements into the vector:" << "1, 2, 3, 4, 5" << endl;
vectorForTest[0] = 1;
vectorForTest[1] = 2;
vectorForTest[2] = 3;
vectorForTest[3] = 4;
vectorForTest[4] = 5;
cout << "2 should be in vector : " << vectorForTest.Exists(2) << endl;
cout << "Size should be 5 : " << vectorForTest.Size() << endl;
cout << "Fold test with sum:" << endl;
int sum1 = vectorForTest.Fold<int>(
    [](const int& acc, const int& element) {
        return acc + element;
    }, 0);
cout << "Sum of elements in the vector: " << sum1 << endl;
cout << "Fold test with product:" << endl;
int product1 = vectorForTest.Fold<int>(
    [](const int& acc, const int& element) {
        return acc * element;
    }, 1);

cout << "Product of elements in the vector: " << product1 << endl;

cout << "Map test doubling the elements:" << endl;
vectorForTest.Map(
    [](int& element) {
        element *= 2;
    }
);

cout << "Elements in the vector after doubling:" << endl;
for (ulong i = 0; i < vectorForTest.Size(); ++i) {
    cout << vectorForTest[i] << " ";
}
    cout << endl <<endl<< " - - -  Vector Tests with string - - - " <<endl<< endl;
    lasd::Vector<string> vectString;
    cout << "vectString should be empty: " << vectString.Empty() << endl;
    cout << "vectString size should be 0: " << vectString.Size() << endl;
    
    vectString.Resize(3);
    
    cout << "vectString size should be 3: " << vectString.Size() << endl;

    cout << "First element of vectString (empty string): " << vectString.Front() << endl;

    cout << "Last element of vectString (empty string): " << vectString.Back() << endl;

    lasd::Vector<string> vectCopyString(vectString);
    cout << "vectCopyString size should be 3: " << vectCopyString.Size() << endl;

    lasd::Vector<string> vectMoveString(move(vectCopyString));
    cout << "vectMoveString size should be 3: " << vectMoveString.Size() << endl;

    cout << "Creating a vector for the fold and map test:" << endl;
    lasd::Vector<string> vectorForTestString(3);

    cout << "Inserting the following elements into the vectStringor:" << "hello  world  !!" <<endl;
    vectorForTestString[0] = "hello";
    vectorForTestString[1] = "world";
    vectorForTestString[2] = "!!";

    cout << "'world' should be in vectString : " << vectorForTestString.Exists("world") << endl;
    cout << "Fold test with concatenation:" << endl;
    string concatString = vectorForTestString.Fold<string>(
        [](const string& acc, const string& element) {
            return acc + element;
        }, "");

    cout << "Concatenated string of elements in the vectString: " << concatString << endl;

    cout << "Map test with adding 'abc' to each element:" << endl;
    vectorForTestString.Map(
        [](string& element) {
            element += "abc";
        }
    );

    cout << "Elements in the vectStringor after modification:" << endl;
    for (ulong i = 0; i < vectorForTestString.Size(); ++i) {
        cout << vectorForTestString[i] << " ";
    }

    cout << endl <<endl<< " - - -  Vector Tests with float - - - " <<endl<< endl;
    lasd::SortableVector<float> vectFloat;
    cout << "vectFloat should be empty: " << vectFloat.Empty() << endl;
    cout << "vectFloat size should be 0: " << vectFloat.Size() << endl;
    
    vectFloat.Resize(4);
    
    cout << "vectFloat size should be 4: " << vectFloat.Size() << endl;


    lasd::SortableVector<float> vectCopyFloat(vectFloat);
    cout << "vectCopyFloat size should be 4: " << vectCopyFloat.Size() << endl;

    lasd::SortableVector<float> vectMoveFloat(move(vectCopyFloat));
    cout << "vectMoveFloat size should be 4: " << vectMoveFloat.Size() << endl;

    cout << "Creating a vector for the fold and map test:" << endl;
    lasd::Vector<float> vectorForTestFloat(4);

    cout << "Inserting the following elements into the vectFloator:" << endl;
    cout << "1.5, 2.5, 3.5, 4.5" << endl;

    vectorForTestFloat[0] = 1.5;
    vectorForTestFloat[1] = 2.5;
    vectorForTestFloat[2] = 3.5;
    vectorForTestFloat[3] = 4.5;


    cout << "First element of vectFloat (1.5): " << vectFloat.Front() << endl;

    cout << "Last element of vectFloat (4.5): " << vectFloat.Back() << endl;

    cout << "2.5 should be in vectFloat : " << vectorForTestFloat.Exists(2.5) << endl;
    cout << "Fold test with sum:" << endl;
    float sum1Float = vectorForTestFloat.Fold<float>(
        [](const float& acc, const float& element) {
            return acc + element;
        }, 0.0);

    cout << "Sum of elements in the vectFloat: " << sum1Float << endl;

    cout << "Fold test with product:" << endl;
    float product1Float = vectorForTestFloat.Fold<float>(
        [](const float& acc, const float& element) {
            return acc * element;
        }, 1.0);

    cout << "Product of elements in the vectFloat: " << product1Float << endl;

cout << endl<<endl << " - - -  List Tests  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" <<endl<< endl;
cout << endl << " - - -  List Tests with integres  - - - " <<endl<< endl;
    lasd::List<int> intList;

    cout << "my List should be empty: " << intList.Empty() << endl;
    cout << "inserting elements into the list:" << endl;
    cout << "5,10,15" << endl;
    intList.InsertAtBack(5);
    intList.InsertAtBack(10);
    intList.InsertAtBack(15);
    cout << "my List size should be 3: " << intList.Size() << endl;
    cout << "First element of my List: " << intList.Front() << endl;
    cout << "Last element of my List: " << intList.Back() << endl;

    cout << "Creating a list for fold test:" <<endl;
    lasd::List<int> listForFold;
    cout << "inserting elements into the list:" <<endl;
    cout << "1, 2, 3, 4, 5" << endl;
    listForFold.InsertAtBack(1);
    listForFold.InsertAtBack(2);
    listForFold.InsertAtBack(3);
    listForFold.InsertAtBack(4);
    listForFold.InsertAtBack(5);

    cout << "Folding the list with +:" << endl;
    int sum = listForFold.PreOrderFold<int>(
        [](const int& acc, const int& element) {
            return acc + element;
        }, 0);

    cout << "Sum of elements in the list: " << sum << endl;

    cout << "Folding the list with *:" << endl;
    int product = listForFold.PreOrderFold<int>(
        [](const int& acc, const int& element) {
            return acc * element;
        }, 1);

    cout << "Product of elements in the list: " << product << endl;
    cout << endl << " - - -  List Tests with String - - - " <<endl<<endl;

    lasd::List<string> stringList;

    cout << "Creating a list for string tests:" << endl;
    cout << "inserting elements into the list:" << endl;
    cout << "Hello, World!" << endl;
    stringList.InsertAtBack("Hello");
    stringList.InsertAtBack(",");
    stringList.InsertAtBack("World!");
    cout << "my List size should be 3: " << stringList.Size() << endl;
    cout << "First element of my List: " << stringList.Front() <<endl;
    cout << "Last element of my List: " << stringList.Back() << endl;
    cout << "Folding the list of strings with concatenation:" <<endl;
    string concatenated = stringList.PostOrderFold<string>(
        [](const string& acc, const string& element) {
            return acc + element;
        }, "");

    cout << "Concatenated string (PostOrder): " << concatenated << endl;

        string concatenated2 = stringList.PreOrderFold<string>(
        [](const string& acc, const string& element) {
            return acc + element;
        }, "");

    cout << "Concatenated string (PreOrder): " << concatenated2 << endl;
    
        cout << endl << " - - -  List Tests with Float - - - " <<endl<< endl;
    lasd::List<float> floatList;

    cout << "Creating a list for float tests:" << endl;
    cout << "inserting elements into the list:" << endl;
    cout << "3.1, 2.7, 1.6" << endl;
    floatList.InsertAtBack(3.1);
    floatList.InsertAtBack(2.7);
    floatList.InsertAtBack(1.6);
    cout << "my List size should be 3: " << floatList.Size() << endl;
    cout << "First element of my List: " << floatList.Front() << endl;
    cout << "Last element of my List: " << floatList.Back() << endl;
cout << endl <<endl<< " - - -  StackLst Tests  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" <<endl<< endl;
    cout << endl << "- - - StackLst Tests with Integers - - -"<<endl << endl;

    lasd::StackLst<int> myStack;

    cout << "myStack should be empty: " << myStack.Empty() << endl;

    cout << "Pushing values into myStack:" << endl;
    cout << "Pushing 5 into myStack" << endl;
    myStack.Push(5);
    cout << "Pushing 10 into myStack" << endl;
    myStack.Push(10);
    cout << "Pushing 15 into myStack" << endl;
    myStack.Push(15);

    cout << "Top element of myStack: " << myStack.Top() << endl;

    myStack.Pop();

    cout << "Top element of myStack after Pop(): " << myStack.Top() << endl;

    cout << "Top element of myStack using TopNPop(): " << myStack.TopNPop() << endl;

    cout << "myStack should not be empty after operations: " << (myStack.Empty() ? "true" : "false") << endl;

    lasd::StackLst<int> anotherStack;
    anotherStack = myStack;
    cout << "anotherStack should be equal to myStack: " << (anotherStack == myStack ? "true" : "false") << endl;

    lasd::StackLst<int> stackdifferente;
    stackdifferente.Push(100);
    cout << "stackdifferente should be different from myStack: " << (stackdifferente != myStack ? "true" : "false") << endl;

    cout << endl << "- - - StackLst Tests with Strings - - -" <<endl<< endl;

    lasd::StackLst<string> stringstacklst;
    cout << "Pushing 'Hello' into stringstacklst" << endl;
    stringstacklst.Push("Hello");
    cout << "Pushing ',' into stringstacklst" << endl;
    stringstacklst.Push(",");
    cout << "Pushing 'World!' into stringstacklst" <<endl;
    stringstacklst.Push("World!");

    cout << "Top element of stringstacklst: " << stringstacklst.Top() << endl;

    cout << endl << "- - - StackLst Tests with Floats - - -"<<endl << endl;

    lasd::StackLst<float> floatstacklst;

    cout << "Pushing float values into floatstacklst:" << endl;
    cout << "Pushing 3.1 into floatstacklst" << endl;
    floatstacklst.Push(3.1);
    cout << "Pushing 2.7 into floatstacklst" << endl;
    floatstacklst.Push(2.7);
    cout << "Pushing 1.6 into floatstacklst" << endl;
    floatstacklst.Push(1.6);

cout << endl <<endl<< " - - -  StackVec Tests  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" <<endl<< endl;
    cout << endl << "- - - StackVec Tests with Integers - - -"<<endl << endl;
lasd::StackVec<int> stack;

cout << "Pushing 5" << endl;
stack.Push(5);
cout << "Pushing 10" << endl;
stack.Push(10);
cout << "Top should be 10: " << stack.Top() << endl;

stack.Pop();
cout << "Top after Pop: " << stack.Top() << endl; 

lasd::StackVec<int> stack2;
cout << "Creating another stack" << endl;
cout << "Pushing 100" << endl;
stack2.Push(100);
cout << "Pushing 200" << endl;
stack2.Push(200);
stack = move(stack2); 
cout << "Top after move assignment: " << stack.Top() << endl; 

int poppedValue = stack.TopNPop();
cout << "Popped value: " << poppedValue << endl; 
cout << "Top after TopNPop: " << stack.Top() << endl; 

lasd::StackVec<int> stack3;
stack3.Push(5);
stack3.Push(10);
cout << "Equal test: " << (stack == stack3) << endl; 

cout << "not equal test: " << (stack != stack3) << endl; 
cout << "Fold test:" << endl;
lasd::StackVec<int> stackForFold;
stackForFold.Push(23);
stackForFold.Push(2);
stackForFold.Push(120);
stackForFold.Push(4);
stackForFold.Push(33);

int sum2 = stackForFold.Fold<int>(
    [](const int& acc, const int& element) {
        return acc + element;
    }, 0);

cout << "Sum of elements in the stack: " << sum2 << endl;
    cout << endl << "- - - StackVec Tests with Floatt - - -"<<endl << endl;
    lasd::StackVec<float> floatStackvec;
    cout << "Pushing 1,2.2,3.3" << endl;
    floatStackvec.Push(1);
    floatStackvec.Push(2.2);
    floatStackvec.Push(3.3);
    float sumFloat = floatStackvec.PreOrderFold<float>(
        [](const float& acc, const float& element) {
            return acc + element;
        }, 0.0);
    cout << "Sum of elements in the stack : " << sumFloat << endl;

    lasd::StackVec<float> floatStackVec;
    cout << "Pushing 1.1,2.2" << endl;
    floatStackVec.Push(1.1);
    floatStackVec.Push(2.2);
    cout << "Top should be 2.2: " << floatStackVec.Top() << endl;

    floatStackVec.Pop();
    cout << "Top after Pop: " << floatStackVec.Top() << endl;

    lasd::StackVec<float> floatStack2;
    cout << "Pushing 100.1,200.2" << endl;
    floatStack2.Push(100.1);
    floatStack2.Push(200.2);
    floatStackVec = move(floatStack2); 
    cout << "Top after move assignment: " << floatStackVec.Top() << endl;

    float poppedFloat = floatStackVec.TopNPop();
    cout << "Popped value: " << poppedFloat << endl; 
    cout << "Top after TopNPop: " << floatStackVec.Top() << endl;



    cout << endl << "- - - StackVec Tests with Stringeh - - -"<<endl << endl;
    lasd::StackVec<string> stringstackkk;
    lasd::StackVec<string> anotherStringStack;
    cout << "Pushing : Simon, Simone" << endl;
    anotherStringStack.Push("Simon");
    anotherStringStack.Push("Simone");
    stringstackkk = move(anotherStringStack); 
    cout << "Top after move assignment: " << stringstackkk.Top() << endl;
    cout << "Popped value: " << stringstackkk.TopNPop() << endl; 
    cout << "Top after TopNPop: " << stringstackkk.Top() << endl;



    
cout << endl <<endl<< " - - -  QueueVec Tests  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" <<endl<< endl;

    cout << endl << "- - - QueueVec Tests with  integers - - -"<<endl << endl;
lasd::QueueVec<int> queue;

cout << "Enqueuing 5" << endl;
queue.Enqueue(5);
cout << "Enqueuing 7" << endl;
queue.Enqueue(7);
cout << "Enqueuing 10" << endl;
queue.Enqueue(10);

cout << "Head, should be 5: " << queue.Head() << endl; 

cout << "Dequeued value, should be 5: " << queue.HeadNDequeue() << endl; 
cout << "Head after HeadNDequeue, should be 10: " << queue.Head() << endl; 

queue.Dequeue();
cout << "Head after Dequeue, should be 10: " << queue.Head() << endl; 

lasd::QueueVec<int> queue2;
queue2.Enqueue(100);
queue2.Enqueue(200);
queue = move(queue2); 
cout << "Head after move assignment, should be 100: " << queue.Head() << endl; 

lasd::QueueVec<int> queue3;
queue3.Enqueue(10);
queue3.Enqueue(20);

cout << "not equal test, should be 1: " << (queue != queue3) << endl;
cout << "Equality test, should be 0: " << (queue == queue3) << endl; 





cout << endl << "- - - QueueVec Tests with strings - - -" << endl << endl;
    lasd::QueueVec<string> simoneQueue;
cout << "Queue SHould be empty: "<<simoneQueue.Empty() << endl;
    cout << "Enqueuing 'simone'" << endl;
    simoneQueue.Enqueue("simone");
    cout << "Enqueuing 'simone123'" << endl;
    simoneQueue.Enqueue("simone123");
    
    cout << "Enqueuing 'simone456'" << endl;
    simoneQueue.Enqueue("simone456");

    cout << "Head, should be 'simone': " << simoneQueue.Head() << endl;

    cout << "Dequeued value, should be 'simone': " << simoneQueue.HeadNDequeue() << endl;
    cout << "Head after HeadNDequeue, should be 'simone123': " << simoneQueue.Head() << endl;

    simoneQueue.Dequeue();
    cout << "Head after Dequeue, should be 'simone123': " << simoneQueue.Head() << endl;

    lasd::QueueVec<string> anotherSimoneQueue;
    anotherSimoneQueue.Enqueue("simone789");
    anotherSimoneQueue.Enqueue("simone101112");
    simoneQueue = move(anotherSimoneQueue);
    cout << "Head after move assignment, should be 'simone789': " << simoneQueue.Head() << endl;

    lasd::QueueVec<string> anotherqueuee;
    anotherqueuee.Enqueue("simone");
    anotherqueuee.Enqueue("simone456");
    cout << "Equality test, should be 0: " << (simoneQueue == anotherqueuee) << endl;

    cout << "Not equal test, should be 1: " << (simoneQueue != anotherqueuee) << endl;

    cout << endl << "- - - QueueVec Tests with floats - - -" << endl << endl;
    lasd::QueueVec<float> floatQueue;

    cout << "Enqueuing 344.44" << endl;
    floatQueue.Enqueue(344.4);
    cout << "Enqueuing 2.66" << endl;
    floatQueue.Enqueue(2.66);
    cout << "Queue size SHould be 2: "<<floatQueue.Size() << endl;
    cout << "Enqueuing 1" << endl;
    floatQueue.Enqueue(1);

    cout << "Head, should be  344.44: " << floatQueue.Head() << endl;

    cout << "Dequeued value, should be  344.44: " << floatQueue.HeadNDequeue() << endl;
    cout << "Head after HeadNDequeue, should be 1: " << floatQueue.Head() << endl;

    floatQueue.Dequeue();
    cout << "Head after Dequeue, should be 1: " << floatQueue.Head() << endl;

    lasd::QueueVec<float> anotherFloatQueue;
    anotherFloatQueue.Enqueue(0.577);
    anotherFloatQueue.Enqueue(1.732);
    floatQueue = move(anotherFloatQueue);
    cout << "Head after move assignment, should be 0.577: " << floatQueue.Head() << endl;

    lasd::QueueVec<float> anotheranotherfloatqueue;
    anotheranotherfloatqueue.Enqueue(3.14);
    anotheranotherfloatqueue.Enqueue(1.618);
    cout << "Equal test, should be 0: " << (floatQueue == anotheranotherfloatqueue) << endl;

    cout << "Not equal test, should be 1: " << (floatQueue != anotheranotherfloatqueue) << endl;


cout << endl <<endl<< " - - -  QueueLst Tests  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" <<endl << endl;
  cout << endl << " - - -  QueueLst Tests with integers  - - -"<<endl << endl;
lasd::QueueLst<int> queuelst1;
queuelst1.Enqueue(5);
queuelst1.Enqueue(10);
queuelst1.Enqueue(16);
queuelst1.Enqueue(13);
queuelst1.Enqueue(14);

cout << "Head of the queue should be 5: " << queuelst1.Head() << endl;
cout << "Size of the queue should be 5: " << queuelst1.Size() << endl;

cout << "Dequeuing elements from the queue:" << endl;
while (!queuelst1.Empty()) {
    cout << "Dequeuing: " << queuelst1.HeadNDequeue() << endl;
}
cout << "Size of the queue after dequeue should be 0: " << queuelst1.Size() << endl;
    
    lasd::QueueLst<int> queuelst2;
    queuelst2.Enqueue(100);
    queuelst2.Enqueue(200);
    queuelst2 = queuelst1;
  cout << "Queue size after copy assignment: " << queuelst2.Size() << endl; 

    lasd::QueueLst<int> queuelst3;
    queuelst3.Enqueue(300);
    queuelst3.Enqueue(400);
    queuelst3 = move(queuelst1);
    cout << "Queue size after move assignment: " << queuelst3.Size() << endl; 
    cout << "Are queuelst1 and queuelst2 equal? " << (queuelst1 == queuelst2) << endl;

    cout << "Are queuelst1 and queuelst3 not equal? " << (queuelst1 != queuelst3) << endl;
  cout << endl << " - - -  QueueLst Tests with Strings  - - - " <<endl<< endl;
    lasd::QueueLst<string> stringQueuesimo;
  cout << "inserting s i m o n e into the uqueue: " <<  endl;
    stringQueuesimo.Enqueue("s");
    stringQueuesimo.Enqueue("i");
    stringQueuesimo.Enqueue("m");
    stringQueuesimo.Enqueue("o");
    stringQueuesimo.Enqueue("n");
    stringQueuesimo.Enqueue("e");

    cout << "Head of the string queue should be 's': " << stringQueuesimo.Head() <<endl;
    cout << "Size of the string queue should be 6: " << stringQueuesimo.Size() << endl;

    cout << "Dequeuing elements from the string queue:" << endl;
    while (!stringQueuesimo.Empty()) {
     cout << "Dequeuing: " << stringQueuesimo.HeadNDequeue() << endl;
    }


    cout << "Size of the string queue after dequeue should be 0: " << stringQueuesimo.Size() << endl;





cout << endl <<endl<< " - - -  BinaryTreeVec Tests  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" <<endl << endl;

  cout << endl << " - - -  BinaryTreeVec Tests with integers  - - -"<<endl << endl;
cout << "creating vector[6] " << endl;
lasd::Vector<int> vecforbtvec(6);
    vecforbtvec[1] = 3;
    cout << "Inserting 3 in vector[1]" << endl;
    vecforbtvec[4] = 120;
    cout << "Inserting 120 in vector[4]" << endl;
    vecforbtvec[2] = 90;
    cout << "Inserting 90 in vector[2]" << endl;

cout << "creating btvec from vector" << endl;
lasd::BinaryTreeVec<int> btvec(vecforbtvec);
    auto btvec_copy = lasd::BinaryTreeVec<int>(btvec);
    cout << "Copied BinaryTreeVec size: " << btvec_copy.Size() << endl;

    auto btvec_move = lasd::BinaryTreeVec<int>(move(btvec));
    cout << "Moved BinaryTreeVec size: " << btvec_move.Size() << endl;

    btvec = btvec_copy;
    cout << "BinaryTreeVec size after copy assignment: " << btvec.Size() << endl;

    btvec = move(btvec_move);
    cout << "BinaryTreeVec size after move assignment: " << btvec.Size() << endl;

    btvec.Clear();
    cout << "BinaryTreeVec size after Clear(): " << btvec.Size() << endl;

    lasd::BinaryTreeVec<int> btvec_equal(vecforbtvec);
    cout << "Are btvec and btvec_equal equal? " << (btvec == btvec_equal) << endl;

    cout << "Are btvec and btvec_equal not equal? " << (btvec != btvec_equal) << endl;

    cout << "Breadth-first traverse of (empty) btvec: ";
    btvec.BreadthTraverse([](const int& value) { cout << value << " "; });
    cout << endl;

  
  cout << endl << " - - -  BinaryTreeVec Tests with Strings  - - -"<<endl << endl;
    lasd::Vector<string> vecforbtvec_string(6);
    vecforbtvec_string[1] = "simone";
    cout << "Inserting 'simone' in vector[1]" << endl;
    vecforbtvec_string[4] = "simo";
    cout << "Inserting 'simo' in vector[4]" << endl;
    vecforbtvec_string[2] = "simooo";
    cout << "Inserting 'simooo' in vector[2]" << endl;

    cout << "creating btvec from string vector" << endl;
    lasd::BinaryTreeVec<string> btvec_string(vecforbtvec_string);
    auto btvec_string_copy = lasd::BinaryTreeVec<string>(btvec_string);
    cout << "Copied BinaryTreeVec size: " << btvec_string_copy.Size() << endl;

    auto btvec_string_move = lasd::BinaryTreeVec<string>(move(btvec_string));
    cout << "Moved BinaryTreeVec size: " << btvec_string_move.Size() << endl;

    btvec_string = btvec_string_copy;
    cout << "BinaryTreeVec size after copy assignment: " << btvec_string.Size() << endl;

    btvec_string = move(btvec_string_move);
    cout << "BinaryTreeVec size after move assignment: " << btvec_string.Size() << endl;

    lasd::BinaryTreeVec<string> btvec_string_equal(vecforbtvec_string);
    cout << "Are btvec_string and btvec_string_equal equal? " << (btvec_string == btvec_string_equal) << endl;

    cout << "Are btvec_string and btvec_string_equal not equal? " << (btvec_string != btvec_string_equal) << endl;

    cout << "PrOrderTrvaerse of btvec_string: ";
    btvec_string.PreOrderTraverse([](const string& value) { cout << value << " "; });
    cout << endl;

        cout << "PostOrderTrvaerse of btvec_string: ";
    btvec_string.PostOrderTraverse([](const string& value) { cout << value << " "; });
    cout << endl;

  cout << endl << " - - -  BinaryTreeVec Tests with Float  - - -"<<endl << endl;
 lasd::Vector<float> vecforbtvec_float(6);
    vecforbtvec_float[1] = 3.69f;
    cout << "Inserting 3.69 in vector[1]" << endl;
    vecforbtvec_float[4] = 6969.0f;
    cout << "Inserting 696969.69 in vector[4]" << endl;
    vecforbtvec_float[2] = 7.1f;
    cout << "Inserting 7.1 in vector[2]" << endl;

    cout << "creating btvec from float vector" << endl;
    lasd::BinaryTreeVec<float> btvec_float(vecforbtvec_float);
    auto btvec_float_copy = lasd::BinaryTreeVec<float>(btvec_float);
    cout << "Copied BinaryTreeVec size: " << btvec_float_copy.Size() << endl;

    auto btvec_float_move = lasd::BinaryTreeVec<float>(move(btvec_float));
    cout << "Moved BinaryTreeVec size: " << btvec_float_move.Size() << endl;

    btvec_float = btvec_float_copy;
    cout << "BinaryTreeVec size after copy assignment: " << btvec_float.Size() << endl;

    btvec_float = move(btvec_float_move);
    cout << "BinaryTreeVec size after move assignment: " << btvec_float.Size() << endl;

    lasd::BinaryTreeVec<float> btvec_float_equal(vecforbtvec_float);
    cout << "Are btvec_float and btvec_float_equal equal? " << (btvec_float == btvec_float_equal) << endl;

    cout << "PreOrderTraverse of btvec_float: ";
    btvec_float.PreOrderTraverse([](const float& value) { cout << value << " "; });
    cout << endl;

    cout << "PreOrderTraverse with sum : ";
    float sum_float = 0.0f;
    btvec_float.PreOrderTraverse([&sum_float](const float& value) { sum_float += value; });
    cout << "Sum: " << sum_float << endl;

    cout << "PreOrderTraverse with product : ";
    float product_float = 1.0f;
    btvec_float.PreOrderTraverse([&product_float](const float& value) { product_float *= value; });
    cout << "Product: " << product_float << endl;


//to do test su binarytreelnk e bst
cout << endl <<endl<< " - - -  BinaryTreeLnk Tests  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" <<endl << endl;
cout << endl << " - - -  BinaryTreeLnk Tests with Integrees  - - -"<<endl << endl;
lasd::BinaryTreeLnk<int> btlnk_int(vecforbtvec);

auto btlnk_int_copy = lasd::BinaryTreeLnk<int>(btlnk_int);
cout << "Copied BinaryTreeLnk size: " << btlnk_int_copy.Size() << endl;

auto btlnk_int_move = lasd::BinaryTreeLnk<int>(move(btlnk_int));
cout << "Moved BinaryTreeLnk size: " << btlnk_int_move.Size() << endl;

btlnk_int = btlnk_int_copy;
cout << "BinaryTreeLnk size after copy assignment: " << btlnk_int.Size() << endl;

btlnk_int = move(btlnk_int_move);
cout << "BinaryTreeLnk size after move assignment: " << btlnk_int.Size() << endl;

lasd::BinaryTreeLnk<int> btlnk_int_equal(vecforbtvec);
cout << "Are btlnk_int and btlnk_int_equal equal? " << (btlnk_int == btlnk_int_equal) << endl;

cout << "PreOrderTraverse of btlnk_int: ";
btlnk_int.PreOrderTraverse([](const int& value) { cout << value << " "; });
cout << endl;

cout << endl << " - - -  BinaryTreeLnk Tests with Strings  - - -"<<endl << endl;

lasd::BinaryTreeLnk<string> btlnk_string(vecforbtvec_string);

auto btlnk_string_copy = lasd::BinaryTreeLnk<string>(btlnk_string);
cout << "Copied BinaryTreeLnk size: " << btlnk_string_copy.Size() << endl;

auto btlnk_string_move = lasd::BinaryTreeLnk<string>(move(btlnk_string));
cout << "Moved BinaryTreeLnk size: " << btlnk_string_move.Size() << endl;

btlnk_string = btlnk_string_copy;
cout << "BinaryTreeLnk size after copy assignment: " << btlnk_string.Size() << endl;

btlnk_string = move(btlnk_string_move);
cout << "BinaryTreeLnk size after move assignment: " << btlnk_string.Size() << endl;

lasd::BinaryTreeLnk<string> btlnk_string_equal(vecforbtvec_string);
cout << "Are btlnk_string and btlnk_string_equal equal? " << (btlnk_string == btlnk_string_equal) << endl;

cout << "PreOrderTraverse of btlnk_string: ";
btlnk_string.PreOrderTraverse([](const string& value) { cout << value << " "; });
cout << endl;
    cout << endl << " - - -  BinaryTreeLnk Tests with Float  - - -"<<endl << endl;

    lasd::BinaryTreeLnk<float> btlnk_float(vecforbtvec_float);

    auto btlnk_float_copy = lasd::BinaryTreeLnk<float>(btlnk_float);
    cout << "Copied BinaryTreeLnk size: " << btlnk_float_copy.Size() << endl;

    auto btlnk_float_move = lasd::BinaryTreeLnk<float>(move(btlnk_float));
    cout << "Moved BinaryTreeLnk size: " << btlnk_float_move.Size() << endl;

    btlnk_float = btlnk_float_copy;
    cout << "BinaryTreeLnk size after copy assignment: " << btlnk_float.Size() << endl;

    btlnk_float = move(btlnk_float_move);
    cout << "BinaryTreeLnk size after move assignment: " << btlnk_float.Size() << endl;

    lasd::BinaryTreeLnk<float> btlnk_float_equal(vecforbtvec_float);
    cout << "Are btlnk_float and btlnk_float_equal equal? " << (btlnk_float == btlnk_float_equal) << endl;

    cout << "PreOrderTraverse of btlnk_float: ";
    btlnk_float.PreOrderTraverse([](const float& value) { cout << value << " "; });
    cout << endl;


  cout << endl <<endl<< " - - -  BST Tests  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" <<endl << endl;
  
  cout << endl << " - - -  BST Tests with integers  - - -"<<endl << endl;
lasd::BST<int> bst_int;
    bst_int.Insert(10);
    bst_int.Insert(5);
    bst_int.Insert(15);
    bst_int.Insert(7);
    bst_int.Insert(3);

    cout << "InOrder traverse of bst_int: ";
    bst_int.InOrderTraverse([](const int& value) { cout << value << " "; });
    cout << endl;

    cout << "Predecessor of 7 in bst_int: " << bst_int.Predecessor(7) << endl;
    cout << "Successor of 7 in bst_int: " << bst_int.Successor(7) << endl;
    cout << "Minimum value in bst_int: " << bst_int.Min() << endl;
    cout << "Maximum value in bst_int: " << bst_int.Max() << endl;
cout << " 10 exists in bst_int? (yes) : " << (bst_int.Exists(10) ? "Yes" : "No") << endl;
cout << "20 exists in bst_int? (no) :" << (bst_int.Exists(20) ? "Yes" : "No") << endl;

    
    cout << "Removing 5 from bst_int..." << endl;
    bst_int.Remove(5);
    cout << "InOrder traverse of bst_int after remove: ";
    bst_int.InOrderTraverse([](const int& value) { cout << value << " "; });
    cout << endl;
    cout << "cLEARING bst_int..." << endl;
    bst_int.Clear();
    cout << "PostOrderTraverse of bst_int after CLEAR (shouldld throw lenth errrror): ";
    try{
        bst_int.PostOrderTraverse([](const int& value) { cout << value << " "; });
    }
    catch(const length_error& e){
        cout << " just catched length error! " ;
    }
cout << endl;


  cout << endl << " - - -  BST Tests with Strings  - - -"<<endl << endl;
 lasd::BST<string> bst_string;
    bst_string.Insert("c");
    bst_string.Insert("i");
    bst_string.Insert("a");
    bst_string.Insert("o");

    cout << "InOrder traverse of bst_string: ";
    bst_string.InOrderTraverse([](const string& value) { cout << value << " "; });
    cout << endl;

    cout << "Predecessor of \"i\" in bst_string: " << bst_string.Predecessor("i") << endl;
    cout << "Successor of \"i\" in bst_string: " << bst_string.Successor("i") << endl;
    cout << "Minimum value in bst_string: " << bst_string.Min() << endl;
    cout << "Maximum value in bst_string: " << bst_string.Max() << endl;
cout << " a exists in bst_string? (yes) : " << (bst_string.Exists("a") ? "Yes" : "No") << endl;
cout << "b exists in bst_string? (no) :" << (bst_string.Exists("b") ? "Yes" : "No") << endl;
    
    cout << "Removing \"a\" from bst_string..." << endl;
    bst_string.Remove("a");
    cout << "PreOrderTraverse of bst_string after remove: ";
    bst_string.PreOrderTraverse([](const string& value) { cout << value << " "; });
    cout << endl; 

  cout << endl << " - - -  BST Tests with Float  - - -"<<endl << endl;
 lasd::BST<float> bst_float;
    bst_float.Insert(90.3);
    bst_float.Insert(56.3);
    bst_float.Insert(33.3);

    cout << "InOrder traverse of bst_float: ";
    bst_float.InOrderTraverse([](const float& value) { cout << value << " "; });
    cout << endl;

    cout << "Predecessor of 56.3 in bst_float: " << bst_float.Predecessor(56.3) << endl;
    cout << "Successor of 56.3 in bst_float: " << bst_float.Successor(56.3) << endl;
    cout << "Minimum value in bst_float: " << bst_float.Min() << endl;
    cout << "Maximum value in bst_float: " << bst_float.Max() << endl;
cout << " 56.3 exists in bst_float? (yes) : " << (bst_float.Exists(56.3) ? "Yes" : "No") << endl;
cout << " 69 exists in bst_float? (no) :" << (bst_float.Exists(69.0) ? "Yes" : "No") << endl;
    
    cout << "Removing 56.3 from bst_float..." << endl;
    bst_float.Remove(56.3);
    cout << "InOrder traverse of bst_float after remove: ";
    bst_float.InOrderTraverse([](const float& value) { cout << value << " "; });
    cout << endl;
    cout << "clearing bst_float..." << endl;
    bst_int.Clear();
    cout << "BreadthTraverse of bst_float after CLEAR (should throw length error because it is empty): ";
    try{
        bst_int.BreadthTraverse([](const int& value) { cout << value << " "; });
    }
    catch(const length_error& e){
        cout << " just catched length error! " <<endl;
    }











cout << endl << " - - -  HashTableOpnAdr Tests  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" <<endl<< endl;


    std::cout << "\n- - - HashTableOpnAdr Tests with Integers - - -" << std::endl;
    {
        lasd::HashTableOpnAdr<int> intHashTable;
        intHashTable.Insert(10);
        intHashTable.Insert(20);
        intHashTable.Insert(30);
        std::cout << "Exists 10: " << intHashTable.Exists(10) << std::endl;
        std::cout << "Exists 40: " << intHashTable.Exists(40) << std::endl;
        intHashTable.Remove(20);
        std::cout << "Exists 20 after removal: " << intHashTable.Exists(20) << std::endl;
        intHashTable.Clear();
        std::cout << "Exists 10 after clear: " << intHashTable.Exists(10) << std::endl;
// Testing Copy Constructor
        intHashTable.Insert(10);
        lasd::HashTableOpnAdr<int> intHashTableCopy(intHashTable);
        std::cout << "Copy Exists 10: " << intHashTableCopy.Exists(10) << std::endl;
// Testing Assignment Operator
        lasd::HashTableOpnAdr<int> intHashTableAssign;
        intHashTableAssign = intHashTable;
        std::cout << "Assign Exists 10: " << intHashTableAssign.Exists(10) << std::endl;
        // Testing Move Constructor
        lasd::HashTableOpnAdr<int> intHashTableMove(std::move(intHashTable));
        std::cout << "Move Exists 10: " << intHashTableMove.Exists(10) << std::endl;

        // Testing Move Assignment Operator
        lasd::HashTableOpnAdr<int> intHashTableMoveAssign;
        intHashTableMoveAssign = std::move(intHashTableMove);
        std::cout << "Move Assign Exists 10: " << intHashTableMoveAssign.Exists(10) << std::endl;

   lasd::Vector<int> intVec(3);
        intVec[0] = 10;
        intVec[1] = 20;
        intVec[2] = 30;

        lasd::HashTableOpnAdr<int> intHashTableFromVec(intVec);
        std::cout << "Construct from Vector Exists 10: " << intHashTableFromVec.Exists(10) << std::endl;
        std::cout << "Construct from Vector Exists 20: " << intHashTableFromVec.Exists(20) << std::endl;
        intHashTableFromVec.Remove(20);
        std::cout << "Exists 20 after removal: " << intHashTableFromVec.Exists(20) << std::endl;

        // Testing Equality Operators
        lasd::HashTableOpnAdr<int> intHashTableEqualityTest1;
        intHashTableEqualityTest1.Insert(10);
        intHashTableEqualityTest1.Insert(20);
        
        lasd::HashTableOpnAdr<int> intHashTableEqualityTest2;
        intHashTableEqualityTest2.Insert(10);
        intHashTableEqualityTest2.Insert(20);

        lasd::HashTableOpnAdr<int> intHashTableInequalityTest;
        intHashTableInequalityTest.Insert(10);
        intHashTableInequalityTest.Insert(30);

        std::cout << "Equality Test (should be true): " << (intHashTableEqualityTest1 == intHashTableEqualityTest2) << std::endl;
        std::cout << "Inequality Test (should be true): " << (intHashTableEqualityTest1 != intHashTableInequalityTest) << std::endl;
   
    }

    std::cout << "\n- - - HashTableOpnAdr Tests with String - - -" << std::endl;
    {
        lasd::HashTableOpnAdr<std::string> stringHashTable;
        stringHashTable.Insert("a");
        stringHashTable.Insert("s");
        stringHashTable.Insert("d");
        std::cout << "Exists 'a': " << stringHashTable.Exists("a") << std::endl;
        std::cout << "Exists 's': " << stringHashTable.Exists("s") << std::endl;
        stringHashTable.Remove("a");
        std::cout << "Exists 'a' after removal: " << stringHashTable.Exists("a") << std::endl;
         // Testing Clear
        stringHashTable.Clear();
        std::cout << "Exists 'd' after clear: " << stringHashTable.Exists("d") << std::endl;
std::cout << "Testing Insertion of Duplicate Element:" << std::endl;

stringHashTable.Insert("a");
std::cout << "Exists 'a' after first insertion: " << stringHashTable.Exists("a") << std::endl;
bool insertResult = stringHashTable.Insert("a"); 
std::cout << "Insertion result of another 'a' (should be false): " << insertResult << std::endl;
std::cout << "Exists 'a' after second insertion attempt: " << stringHashTable.Exists("a") << std::endl;
stringHashTable.Clear();
        // Testing Copy Constructor
        stringHashTable.Insert("a");
        lasd::HashTableOpnAdr<std::string> stringHashTableCopy(stringHashTable);
        std::cout << "Copy Exists 'a': " << stringHashTableCopy.Exists("a") << std::endl;

        // Testing Assignment Operator
        lasd::HashTableOpnAdr<std::string> stringHashTableAssign;
        stringHashTableAssign = stringHashTable;
        std::cout << "Assign Exists 'a': " << stringHashTableAssign.Exists("a") << std::endl;

        // Testing Move Constructor
        lasd::HashTableOpnAdr<std::string> stringHashTableMove(std::move(stringHashTable));
        std::cout << "Move Exists 'a': " << stringHashTableMove.Exists("a") << std::endl;

        // Testing Move Assignment Operator
        lasd::HashTableOpnAdr<std::string> stringHashTableMoveAssign;
        stringHashTableMoveAssign = std::move(stringHashTableMove);

        std::cout << "Move Assign Exists 'a': " << stringHashTableMoveAssign.Exists("a") << std::endl;

        lasd::Vector<std::string> stringVec;
        stringVec.Resize(3);
        stringVec[0] = "a";
        stringVec[1] = "s";
        stringVec[2] = "d";

        lasd::HashTableOpnAdr<std::string> stringHashTableFromVec(stringVec);
        std::cout << "Construct from Vector Exists 'a': " << stringHashTableFromVec.Exists("a") << std::endl;
        std::cout << "Construct from Vector Exists 's': " << stringHashTableFromVec.Exists("s") << std::endl;
  
// Testing Equality Operators
lasd::HashTableOpnAdr<std::string> stringHashTableEqualityTest1;
stringHashTableEqualityTest1.Insert("a");
stringHashTableEqualityTest1.Insert("s");

lasd::HashTableOpnAdr<std::string> stringHashTableEqualityTest2;
stringHashTableEqualityTest2.Insert("a");
stringHashTableEqualityTest2.Insert("s");

lasd::HashTableOpnAdr<std::string> stringHashTableInequalityTest;
stringHashTableInequalityTest.Insert("a");
stringHashTableInequalityTest.Insert("d");

std::cout << "Equality Test (should be true): " << (stringHashTableEqualityTest1 == stringHashTableEqualityTest2) << std::endl;
std::cout << "Inequality Test (should be true): " << (stringHashTableEqualityTest1 != stringHashTableInequalityTest) << std::endl;

    }

    std::cout << "\n- - - HashTableOpnAdr Tests with Double - - -" << std::endl;
    {
        lasd::HashTableOpnAdr<double> floatHashTable;
        floatHashTable.Insert(1.1f);
        floatHashTable.Insert(2.2f);
        floatHashTable.Insert(3.3f);
        std::cout << "size of floathahtable should be 0 : " <<  floatHashTable.Size() << std::endl;
         std::cout << "inserting another time 1.1 should be 0 : " <<  floatHashTable.Insert(1.1f) << std::endl;
        std::cout << "Exists 1.1: " << floatHashTable.Exists(1.1f) << std::endl;
        std::cout << "Exists 4.4: " << floatHashTable.Exists(4.4f) << std::endl;
        floatHashTable.Remove(2.2f);
        std::cout << "Exists 2.2 after removal: " << floatHashTable.Exists(2.2f) << std::endl;
    
        floatHashTable.Clear();
        std::cout << "Exists 1.1 after clear: " << floatHashTable.Exists(1.1) << std::endl;

        // Testing Copy Constructor
        floatHashTable.Insert(1.1);
        lasd::HashTableOpnAdr<double> floatHashTableCopy(floatHashTable);
        std::cout << "Copy Exists 1.1: " << floatHashTableCopy.Exists(1.1) << std::endl;

        // Testing Assignment Operator
        lasd::HashTableOpnAdr<double> floatHashTableAssign;
        floatHashTableAssign = floatHashTable;
        std::cout << "Assign Exists 1.1: " << floatHashTableAssign.Exists(1.1) << std::endl;

        // Testing Move Constructor
        lasd::HashTableOpnAdr<double> floatHashTableMove(std::move(floatHashTable));
        std::cout << "Move Exists 1.1: " << floatHashTableMove.Exists(1.1) << std::endl;

        // Testing Move Assignment Operator
        lasd::HashTableOpnAdr<double> floatHashTableMoveAssign;
        floatHashTableMoveAssign = std::move(floatHashTableMove);
        std::cout << "Move Assign Exists 1.1: " << floatHashTableMoveAssign.Exists(1.1) << std::endl;
        lasd::Vector<double> doubleVec;
doubleVec.Resize(3);
doubleVec[0] = 1.1;
doubleVec[1] = 2.2;
doubleVec[2] = 3.3;

lasd::HashTableOpnAdr<double> doubleHashTableFromVec(doubleVec);
std::cout << "Construct from Vector Exists 1.1: " << doubleHashTableFromVec.Exists(1.1) << std::endl;
std::cout << "Construct from Vector Exists 2.2: " << doubleHashTableFromVec.Exists(2.2) << std::endl;
std::cout << "Construct from Vector Exists 2.3: " << doubleHashTableFromVec.Exists(2.3) << std::endl;
// Testing Equality Operators
lasd::HashTableOpnAdr<double> doubleHashTableEqualityTest1;
doubleHashTableEqualityTest1.Insert(1.1);
doubleHashTableEqualityTest1.Insert(2.2);

lasd::HashTableOpnAdr<double> doubleHashTableEqualityTest2;
doubleHashTableEqualityTest2.Insert(1.1);
doubleHashTableEqualityTest2.Insert(2.2);

lasd::HashTableOpnAdr<double> doubleHashTableInequalityTest;
doubleHashTableInequalityTest.Insert(1.1);
doubleHashTableInequalityTest.Insert(3.3);

std::cout << "Equality Test (should be true): " << (doubleHashTableEqualityTest1 == doubleHashTableEqualityTest2) << std::endl;
std::cout << "Equality Test (should be false): " << (doubleHashTableEqualityTest1 == doubleHashTableInequalityTest) << std::endl;
std::cout << "Inequality Test (should be true): " << (doubleHashTableEqualityTest1 != doubleHashTableInequalityTest) << std::endl;
   
    }
cout << endl << " - - -  HashTableClsAdr Tests  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" <<endl<< endl;
   
    std::cout << "\n- - - HashTableClsAdr Tests with Integers - - -" << std::endl;
        {
        lasd::HashTableClsAdr<int> intHashTable(4);
        intHashTable.Insert(10);
        intHashTable.Insert(20);
        intHashTable.Insert(30);
        std::cout << "Exists 10 (1): " << intHashTable.Exists(10) << std::endl;
        std::cout << "Exists 40 (0): " << intHashTable.Exists(40) << std::endl;
        intHashTable.Remove(20);
        std::cout << "Exists 20 after removal (0): " << intHashTable.Exists(20) << std::endl;

        // Testing Insert of Duplicate Element
        bool insertResult = intHashTable.Insert(10); // Duplicate insertion
        std::cout << "Insert Duplicate 10 (should be false): " << insertResult << std::endl;

        // Testing Clear
        intHashTable.Clear();
        std::cout << "Exists 10 after clear (0): " << intHashTable.Exists(10) << std::endl;

        // Testing Copy Constructor
        intHashTable.Insert(10);
        lasd::HashTableClsAdr<int> intHashTableCopy(intHashTable);
        std::cout << "in Copy Exists 10: " << intHashTableCopy.Exists(10) << std::endl;

        // Testing Assignment Operator
        lasd::HashTableClsAdr<int> intHashTableAssign = intHashTable;
        std::cout << "in Assign Exists 10: " << intHashTableAssign.Exists(10) << std::endl;

        // Testing Move Constructor
        lasd::HashTableClsAdr<int> intHashTableMove(std::move(intHashTable));
        std::cout << "in Move c Exists 10: " << intHashTableMove.Exists(10) << std::endl;

        // Testing Move Assignment Operator
        lasd::HashTableClsAdr<int> intHashTableMoveAssign= std::move(intHashTableMove);
        std::cout << " in Move Assign Exists 10: " << intHashTableMoveAssign.Exists(10) << std::endl;
   cout << "Size of intHashTableMoveAssign: " << intHashTableMoveAssign.Size() << std::endl;

  // creo due tabelle hash uguali
    lasd::HashTableClsAdr<int> intHashTable1(127);
    intHashTable1.Insert(1);
    intHashTable1.Insert(2);
    intHashTable1.Insert(3);
std::cout<<"size of inthashtable1: "<<intHashTable1.Size()<<""<<std::endl;
    lasd::HashTableClsAdr<int> intHashTable2(127);
    intHashTable2.Insert(1);
    intHashTable2.Insert(2);
    intHashTable2.Insert(3);
std::cout<<"size of inthashtable2: "<<intHashTable2.Size()<<std::endl;
    // Test dell'operatore ==
    cout << "\nTesting equality operator:" << endl;
    cout << "intHashTable1 == intHashTable2: " << (intHashTable1 == intHashTable2) << endl;
lasd::HashTableClsAdr<int> intHashTable44(intHashTable2);
    cout << "\nTesting equality operator after assign:" << endl;
    cout << "intHashTable1 == intHashTable2: " << (intHashTable44 == intHashTable2) << endl;
    // Test dell'operatore !=
    cout << "\nTesting inequality operator:" << endl;
    cout << "intHashTable1 != intHashTable2: " << (intHashTable1 != intHashTable2) << endl;

    // Modifica della seconda tabella hash
    intHashTable2.Remove(2);

    // Test dell'operatore == dopo la modifica
    cout << "\ntesting equality operator after modification:" << endl;
    cout << "intHashTable1 == intHashTable2: " << (intHashTable1 == intHashTable2) << endl;

    // Test dell'operatore != dopo la modifica
    cout << "\nTesting inequality operator after modification:" << endl;
    cout << "intHashTable1 != intHashTable2: " << (intHashTable1 != intHashTable2) << endl;

 lasd::Vector<int> intVector(3);
        intVector[0] = 100;
        intVector[1] = 200;
        intVector[2] = 300;

        // Testing Constructor from Vector
        lasd::HashTableClsAdr<int> intHashTableFromVector(intVector);
        std::cout << "in constructor (without size) From Vector Exists 100: " << intHashTableFromVector.Exists(100) << std::endl;
        std::cout << "Exists 200: " << intHashTableFromVector.Exists(200) << std::endl;
        std::cout << "Exists 300: " << intHashTableFromVector.Exists(300) << std::endl;

        // Testing Constructor with Size from Vector
        lasd::HashTableClsAdr<int> intHashTableFromVectorWithSize(10, intVector);
        std::cout << "in construcotr From Vector (with Size) Exists 100: " << intHashTableFromVectorWithSize.Exists(100) << std::endl;
        std::cout << "From Vector with Size Exists 200: " << intHashTableFromVectorWithSize.Exists(200) << std::endl;
        std::cout << "From Vector with Size Exists 300: " << intHashTableFromVectorWithSize.Exists(300) << std::endl;
  
  //costruttore e default 
          lasd::HashTableClsAdr<int> intHashTableDefault;
        intHashTableDefault.Insert(42);
        std::cout << "in Default Constructor Exists 42: " << intHashTableDefault.Exists(42) << std::endl;
 std::cout << "in Default Constructor re-inserting 42 (should be 0): " << intHashTableDefault.Insert(42) << std::endl;
std::cout<<"clearing intHashTableDefault"<<std::endl;
intHashTableDefault.Clear();
std::cout<<"checking size : "<<intHashTableDefault.Size()<<std::endl;

 //penso di aver testato tutto 
    }

       std::cout << "\n- - - HashTableClsAdr Tests with Strings - - -" << std::endl;
    {
        lasd::HashTableClsAdr<std::string> stringHashTable(4);
        stringHashTable.Insert("a");
        stringHashTable.Insert("s");
        stringHashTable.Insert("d");
        std::cout << "Exists 'a': " << stringHashTable.Exists("a") << std::endl;
        std::cout << "Exists 'c': " << stringHashTable.Exists("c") << std::endl;
        stringHashTable.Remove("s");
        std::cout << "Exists 's' after removal: " << stringHashTable.Exists("s") << std::endl;

        // Testing Insert of Duplicate Element
        bool insertResult = stringHashTable.Insert("a"); // Duplicate insertion
        std::cout << "Insert Duplicate 'a' (should be false): " << insertResult << std::endl;

        // Testing Clear
        stringHashTable.Clear();
        std::cout << "Exists 'a' after clear: " << stringHashTable.Exists("a") << std::endl;

        // Testing Copy Constructor
        stringHashTable.Insert("a");
        lasd::HashTableClsAdr<std::string> stringHashTableCopy(stringHashTable);
        std::cout << "Copy Exists 'a': " << stringHashTableCopy.Exists("a") << std::endl;

        // Testing Assignment Operator
        lasd::HashTableClsAdr<std::string> stringHashTableAssign = stringHashTable;
        std::cout << "Assign Exists 'a': " << stringHashTableAssign.Exists("a") << std::endl;

        // Testing Move Constructor
        lasd::HashTableClsAdr<std::string> stringHashTableMove(std::move(stringHashTable));
        std::cout << "Move Exists 'a': " << stringHashTableMove.Exists("a") << std::endl;

        // Testing Move Assignment Operator
        lasd::HashTableClsAdr<std::string> stringHashTableMoveAssign = std::move(stringHashTableMove);
        std::cout << "Move Assign Exists 'a': " << stringHashTableMoveAssign.Exists("a") << std::endl;
        std::cout << "Size of stringHashTableMoveAssign: " << stringHashTableMoveAssign.Size() << std::endl;

        // Creazione di due tabelle hash identiche
        lasd::HashTableClsAdr<std::string> stringHashTable1(127);
        stringHashTable1.Insert("w");
        stringHashTable1.Insert("o");
        stringHashTable1.Insert("p");
        std::cout << "size of stringHashTable1: " << stringHashTable1.Size() << std::endl;
        lasd::HashTableClsAdr<std::string> stringHashTable2(127);
        stringHashTable2.Insert("w");
        stringHashTable2.Insert("o");
        stringHashTable2.Insert("p");
        std::cout << "size of stringHashTable2: " << stringHashTable2.Size() << std::endl;

        // Test dell'operatore ==
        std::cout << "\nTesting equality operator:" << std::endl;
        std::cout << "stringHashTable1 == stringHashTable2: " << (stringHashTable1 == stringHashTable2) << std::endl;

        // Test dell'operatore !=
        std::cout << "\nTesting inequality operator:" << std::endl;
        std::cout << "stringHashTable1 != stringHashTable2: " << (stringHashTable1 != stringHashTable2) << std::endl;

        // Modifica della seconda tabella hash
        stringHashTable2.Remove("w");

        // Test dell'operatore == dopo la modifica
        std::cout << "\nTesting equality operator after modification:" << std::endl;
        std::cout << "stringHashTable1 == stringHashTable2: " << (stringHashTable1 == stringHashTable2) << std::endl;

        // Test dell'operatore != dopo la modifica
        std::cout << "\nTesting inequality operator after modification:" << std::endl;
        std::cout << "stringHashTable1 != stringHashTable2: " << (stringHashTable1 != stringHashTable2) << std::endl;

        lasd::Vector<std::string> stringVector(3);
        stringVector[0] = "x";
        stringVector[1] = "y";
        stringVector[2] = "z";

        // Testing Constructor from Vector
        lasd::HashTableClsAdr<std::string> stringHashTableFromVector(stringVector);
        std::cout << "From Vector without size Exists 'x': " << stringHashTableFromVector.Exists("x") << std::endl;
        std::cout << "From Vector Exists 'y': " << stringHashTableFromVector.Exists("y") << std::endl;
        std::cout << "From Vector Exists 'z': " << stringHashTableFromVector.Exists("z") << std::endl;

        // Testing Constructor with Size from Vector
        lasd::HashTableClsAdr<std::string> stringHashTableFromVectorWithSize(10, stringVector);
        std::cout << "From Vector with Size Exists 'x': " << stringHashTableFromVectorWithSize.Exists("x") << std::endl;
        std::cout << "From Vector with Size Exists 'y': " << stringHashTableFromVectorWithSize.Exists("y") << std::endl;
        std::cout << "From Vector with Size Exists 'z': " << stringHashTableFromVectorWithSize.Exists("z") << std::endl;

        // Costruttore di default
        lasd::HashTableClsAdr<std::string> stringHashTableDefault;
        stringHashTableDefault.Insert("h");
        std::cout << "Default Constructor Exists 'h': " << stringHashTableDefault.Exists("h") << std::endl;
    }

    std::cout << "\n- - - HashTableClsAdr Tests with Dohuuble - - -" << std::endl;
    {
                lasd::HashTableClsAdr<double> doubleHashTable(4);

        // Inserimento di alcuni valori
        doubleHashTable.Insert(1.1);
        doubleHashTable.Insert(2.2);
        doubleHashTable.Insert(3.3);

        // Verifica della presenza di alcuni valori
        std::cout << "Exists 1.1: " << doubleHashTable.Exists(1.1) << std::endl;
        std::cout << "Exists 4.4: " << doubleHashTable.Exists(4.4) << std::endl;

        // Rimozione di un valore e verifica della sua presenza
        doubleHashTable.Remove(2.2);
        std::cout << "Exists 2.2 after removal: " << doubleHashTable.Exists(2.2) << std::endl;

        
        std::cout << "Inserting 2.2 again: " << doubleHashTable.Insert(2.2) << std::endl;

        // Testing Clear
        doubleHashTable.Clear();
        std::cout << "Exists 1.1 after clear: " << doubleHashTable.Exists(1.1) << std::endl;

        // Testing Copy Constructor
       std::cout << "reinserting 1.1: " <<  doubleHashTable.Insert(1.1)<<std::endl;
       std::cout << "Exists 1.1: " << doubleHashTable.Exists(1.1) << std::endl;
        lasd::HashTableClsAdr<double> doubleHashTableCopy(doubleHashTable);
        std::cout << "Copy Exists 1.1: " << doubleHashTableCopy.Exists(1.1) << std::endl;
std::cout << "Size of Copy : " << doubleHashTableCopy.Size() << std::endl;
std::cout << "remove 1.1 from doublehashtable: " <<  doubleHashTable.Remove(1.1)<<std::endl;
std::cout << "Copy Exists 1.1: " << doubleHashTableCopy.Exists(1.1) << std::endl; //reimplementare costruttore di copia 
std::cout << " ORA reinserting 1.1: " <<  doubleHashTableCopy.Insert(1.1)<<std::endl;
std::cout << "Copy Exists 1.1: " << doubleHashTableCopy.Exists(1.1) << std::endl;

        // Testing Assignment Operator
               std::cout << "reinserting 1.1: " <<  doubleHashTable.Insert(1.1)<<std::endl;
        lasd::HashTableClsAdr<double> doubleHashTableAssign = doubleHashTable;
        std::cout << "Assign Exists 1.1: " << doubleHashTableAssign.Exists(1.1) << std::endl;
std::cout << "Size of Assign : " << doubleHashTableAssign.Size() << std::endl;
        // Testing Move Constructor
        lasd::HashTableClsAdr<double> doubleHashTableMove(std::move(doubleHashTable)); //reimplementare costr di move
        std::cout << "Move Exists 1.1: " << doubleHashTableMove.Exists(1.1) << std::endl;
std::cout << "Size of doubleHashTableMove: " << doubleHashTableMove.Size() << std::endl;
        // Testing Move Assignment Operator
        lasd::HashTableClsAdr<double> doubleHashTableMoveAssign = std::move(doubleHashTableMove);
        std::cout << "Move Assign Exists 1.1: " << doubleHashTableMoveAssign.Exists(1.1) << std::endl;
        std::cout << "Size of doubleHashTableMoveAssign: " << doubleHashTableMoveAssign.Size() << std::endl;

        // Creazione di due tabelle hash identiche
        lasd::HashTableClsAdr<double> doubleHashTable1(127);
        doubleHashTable1.Insert(1.1);
        doubleHashTable1.Insert(2.2);
        doubleHashTable1.Insert(3.3);

        lasd::HashTableClsAdr<double> doubleHashTable2(127);
        doubleHashTable2.Insert(1.1);
        doubleHashTable2.Insert(2.2);
        doubleHashTable2.Insert(3.3);

        // Test dell'operatore ==
        std::cout << "\nTesting equality operator:" << std::endl;
        std::cout << "doubleHashTable1 == doubleHashTable2: " << (doubleHashTable1 == doubleHashTable2) << std::endl;

        // Test dell'operatore !=
        std::cout << "\nTesting inequality operator:" << std::endl;
        std::cout << "doubleHashTable1 != doubleHashTable2: " << (doubleHashTable1 != doubleHashTable2) << std::endl;

        // Modifica della seconda tabella hash
        doubleHashTable2.Remove(2.2);

        // Test dell'operatore == dopo la modifica
        std::cout << "\nTesting equality operator after modification:" << std::endl;
        std::cout << "doubleHashTable1 == doubleHashTable2: " << (doubleHashTable1 == doubleHashTable2) << std::endl;

        // Test dell'operatore != dopo la modifica
        std::cout << "\nTesting inequality operator after modification:" << std::endl;
        std::cout << "doubleHashTable1 != doubleHashTable2: " << (doubleHashTable1 != doubleHashTable2) << std::endl;

        // Creazione di un vettore di double
        lasd::Vector<double> doubleVector(3);
        doubleVector[0] = 1.1;
        doubleVector[1] = 2.2;
        doubleVector[2] = 3.3;

        // Testing Constructor from Vector
        lasd::HashTableClsAdr<double> doubleHashTableFromVector(doubleVector);
        std::cout << "From Vector without size Exists 1.1: " << doubleHashTableFromVector.Exists(1.1) << std::endl;
        std::cout << "From Vector Exists 2.2: " << doubleHashTableFromVector.Exists(2.2) << std::endl;
        std::cout << "From Vector Exists 3.3: " << doubleHashTableFromVector.Exists(3.3) << std::endl;

        // Testing Constructor with Size from Vector
        lasd::HashTableClsAdr<double> doubleHashTableFromVectorWithSize(10, doubleVector);
        std::cout << "From Vector with Size Exists 1.1: " << doubleHashTableFromVectorWithSize.Exists(1.1) << std::endl;
        std::cout << "From Vector with Size Exists 2.2: " << doubleHashTableFromVectorWithSize.Exists(2.2) << std::endl;
        std::cout << "From Vector with Size Exists 3.3: " << doubleHashTableFromVectorWithSize.Exists(3.3) << std::endl;

        // Costruttore di default
        lasd::HashTableClsAdr<double> doubleHashTableDefault;
        doubleHashTableDefault.Insert(1.1);
        std::cout << "Default Constructor Exists 1.1: " << doubleHashTableDefault.Exists(1.1) << std::endl;
  //test costruttore da list
        lasd::List<double> doubleList;
        doubleList.Insert(1.1f);
        doubleList.Insert(2.2f);
        doubleList.Insert(3.3f);
lasd::HashTableClsAdr<double> doubleHashTableFromList(doubleList);
        std::cout << "From List Exists 2.2: " << doubleHashTableFromVectorWithSize.Exists(2.2) << std::endl;


    }

    cout << endl<<endl <<endl <<"Goodbye!" <<  endl<<endl<<endl;
}