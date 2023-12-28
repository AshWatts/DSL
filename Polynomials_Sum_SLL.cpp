#include <iostream>

using namespace std;

struct Node 
{
    int coefficient;
    int exponent;
    Node* next;
};

// Function to add a node to the end of a linked list
void appendNode(Node*& head, Node*& tail, int coeff, int exp) 
{
    Node* newNode = new Node();
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = nullptr;

    if (head == nullptr) 
    {
        head = tail = newNode;
    } 
    else 
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) 
{
    Node* resultHead = nullptr;  // Head of the resulting polynomial
    Node* resultTail = nullptr;  // Tail of the resulting polynomial

    // Traverse both lists simultaneously
    while (poly1 != nullptr && poly2 != nullptr) 
    {
        // Compare exponents
        if (poly1->exponent > poly2->exponent) 
        {
            // Add poly1 node to result
            appendNode(resultHead, resultTail, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) 
        {
            // Add poly2 node to result
            appendNode(resultHead, resultTail, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            // Add nodes with equal exponents
            int sumCoeff = poly1->coefficient + poly2->coefficient;
            if (sumCoeff != 0) {
                appendNode(resultHead, resultTail, sumCoeff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Append remaining nodes from either list
    while (poly1 != nullptr) {
        appendNode(resultHead, resultTail, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != nullptr) {
        appendNode(resultHead, resultTail, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return resultHead;
}

// Function to print a polynomial
void printPolynomial(Node* head) {
    while (head != nullptr) {
        cout << head->coefficient << "x^" << head->exponent;
        if (head->next != nullptr) {
            cout << " + ";
        }
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create two sample polynomials as linked lists
    Node* poly1 = nullptr;
    appendNode(poly1, poly1, 2, 3);
    appendNode(poly1, poly1, -1, 2);
    appendNode(poly1, poly1, 1, 0);

    Node* poly2 = nullptr;
    appendNode(poly2, poly2, 3, 2);
    appendNode(poly2, poly2, -2, 1);

    // Add the polynomials
    Node* result = addPolynomials(poly1, poly2);

    // Print the original polynomials and the result
    cout << "Polynomial 1: ";
    printPolynomial(poly1);
    cout << "Polynomial 2: ";
    printPolynomial(poly2);
    cout << "Result: ";
    printPolynomial(result);

    return 0;
}
