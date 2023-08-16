//chess game, player could drag piece to make a movee


//view 
//has method for mouse drag, delegate player action to controller
void ChessView::handleMouseDrag(Point start, Point end){
    controller->handleMouseDrag(start, end);
}

//controller 
//translates user interface even to game model
void ChessController::handleMouseDrag(Point start, Point end){
    Piece piece = findPiece(start);
    Position position = findBoardPosition(end);
    model->movePieceTo(piece, position); //sends it to model to handle game action
}

//model
//logic to handle game action
void ChessModel::movePieceTo(Piece piece, Position position){
    if(isValidMove(piece, position)){
        //update state of internal fields to put piece in the new position
        //position: check other consequences of new piece position
        //e.g. if the player won the game, capture an enemy piece 
        notifyViews();
    }
}

void ChessModel::notifyViews(){
    //subject implementation 
    //notifys all observers
    for( int i = 0; i < views.size(); i++){
        views.at[i].update();
    }
}

//each view has concreate implementation of the updated method 
void ChessView::update(){
    //read the updated state from tthe model
    //redraw the game board in the user interface
}

