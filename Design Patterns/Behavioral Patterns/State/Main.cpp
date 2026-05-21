#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Forward declaration
class Document;

// DocumentState interface
class DocumentState {
public:
    virtual ~DocumentState() = default;
    
    virtual void edit(Document& context, const string& content) = 0;
    virtual void submitForReview(Document& context) = 0;
    virtual void approve(Document& context) = 0;
    virtual void reject(Document& context) = 0;
    virtual void unpublish(Document& context) = 0;
};

// DraftState implementation
class DraftState : public DocumentState {
public:
    void edit(Document& context, const string& content) override;
    void submitForReview(Document& context) override;
    void approve(Document& context) override {
        cout << "Cannot approve a draft. Submit for review first." << endl;
    }
    void reject(Document& context) override {
        cout << "Cannot reject a draft. Submit for review first." << endl;
    }
    void unpublish(Document& context) override {
        cout << "Document is already a draft." << endl;
    }
};

// UnderReviewState implementation
class UnderReviewState : public DocumentState {
public:
    void edit(Document& context, const string& content) override {
        cout << "Cannot edit while under review." << endl;
    }
    void submitForReview(Document& context) override {
        cout << "Document is already under review." << endl;
    }
    void approve(Document& context) override;
    void reject(Document& context) override;
    void unpublish(Document& context) override {
        cout << "Document is not published yet." << endl;
    }
};

// PublishedState implementation
class PublishedState : public DocumentState {
public:
    void edit(Document& context, const string& content) override {
        cout << "Cannot edit a published document. Unpublish first." << endl;
    }
    void submitForReview(Document& context) override {
        cout << "Document is already published." << endl;
    }
    void approve(Document& context) override {
        cout << "Document is already published." << endl;
    }
    void reject(Document& context) override {
        cout << "Cannot reject a published document." << endl;
    }
    void unpublish(Document& context) override;
};

// Document context class
class Document {
private:
    unique_ptr<DocumentState> currentState;
    string content;

public:
    Document() : currentState(make_unique<DraftState>()), content("") {}
    
    void setState(unique_ptr<DocumentState> state) {
        currentState = move(state);
    }
    
    void setContent(const string& newContent) {
        content = newContent;
    }
    
    string getContent() const {
        return content;
    }
    
    void edit(const string& newContent) {
        currentState->edit(*this, newContent);
    }
    
    void submitForReview() {
        currentState->submitForReview(*this);
    }
    
    void approve() {
        currentState->approve(*this);
    }
    
    void reject() {
        currentState->reject(*this);
    }
    
    void unpublish() {
        currentState->unpublish(*this);
    }
};

// Implement DraftState methods
void DraftState::edit(Document& context, const string& content) {
    cout << "Editing document: " << content << endl;
    context.setContent(content);
}

void DraftState::submitForReview(Document& context) {
    cout << "Document submitted for review." << endl;
    context.setState(make_unique<UnderReviewState>());
}

// Implement UnderReviewState methods
void UnderReviewState::approve(Document& context) {
    cout << "Document approved and published." << endl;
    context.setState(make_unique<PublishedState>());
}

void UnderReviewState::reject(Document& context) {
    cout << "Document rejected. Returning to draft." << endl;
    context.setState(make_unique<DraftState>());
}

// Implement PublishedState methods
void PublishedState::unpublish(Document& context) {
    cout << "Document unpublished. Returning to draft." << endl;
    context.setState(make_unique<DraftState>());
}

// Main function - Usage
int main() {
    Document doc;
    
    doc.edit("First draft of the article.");
    doc.approve();              // Rejected: cannot approve a draft
    doc.submitForReview();
    doc.edit("Trying to edit");  // Rejected: under review
    doc.reject();                // Back to draft
    doc.edit("Revised draft.");
    doc.submitForReview();
    doc.approve();               // Published
    doc.edit("Trying to edit");  // Rejected: published
    doc.unpublish();             // Back to draft
    
    return 0;
}
