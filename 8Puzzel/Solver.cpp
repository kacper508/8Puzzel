#include "Solver.h"


Solver::Solver(sf::Font& Font,Board& board)
{
	Squares.resize(9);
	TextInsideSquares.resize(9);
	textSettings(Font);
	getValues(board);
	updateSolverBoard(board);
	createSolverBoard(Font);
}

Solver::~Solver()
{
}

void Solver::textSettings(sf::Font& Font)
{
	int index = 0;
	for (sf::Text text : TextInsideSquares)
	{
		text.setFillColor(sf::Color::White);
		text.setStyle(sf::Text::Bold);
		text.setCharacterSize(20);
		text.setFont(Font);
		text.setPosition(sf::Vector2f(200 + index * (40), 600 + index * 40));
		index++;
	}
}

void Solver::getValues(Board& Board)
{
	//while (!openList.empty()) delete openList.front(), openList.pop_front();

	//while (!closedList.empty()) delete closedList.front(), closedList.pop_front();

	openList.clear();
	closedList.clear();
	//if (openList.size() == 0)
	//	//std::cout << "open\n";
	//if (closedList.size() == 0)
	//	//std::cout << "closed\n";

	Node* temp = new Node;
	temp->getValue(Board.valueBoard);
	//temp->display();

	temp->updateZeroPosition();
	temp->manhattanDistance();
	temp->setG(0);
	temp->setF();

	openList.push_back(temp);

	//for (auto t : openList)
	//{
	//	t->display();
	//	std::cout << "\n";
	//}
	//std::cout << "--------\n";
	bool over = false;

	while (!over)
	{
		Node* te = openList.front();
		openList.pop_front();
		//std::cout << te->getH() << " = H\n";
		//std::cout << "CHOOSEN\n";
		//te->display();
		//std::cout << "CHOOSEN\n";
		if (te->getH() == 0)
		{

			//std::cout << "IS OVER\n";
			over = !over;
			/*solvedList.clear()*/;
			solved.clear();
			while (te)
			{
				/*solvedList.push_back(te);*/
				solved.push_back(te);
				te = te->getParent();
				//this->order = solvedList.size() - 1;
				this->order = solved.size() - 1;
			}
			break;
		}
		else
		{
			//std::cout << "2\n";
			createChildren(te,openList,closedList);
			closedList.push_back(te);
			//te->display();
			sortList(openList);
		}
	}
}

void Solver::drawSolverBoard(sf::RenderWindow& window)
{
	for (auto& square : this->Squares)
	{
		window.draw(square.getRectangleShape());
	}

	for (sf::Text text : TextInsideSquares)
	{
		window.draw(text);
	}
}

void Solver::updateSolverBoard(Board& board)
{
	this->updateValues(board);
	int index = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			this->Squares[index].setSquareFillColor(sf::Color::Blue);
			this->TextInsideSquares[index].setString(std::to_string(this->values[i][j]-48));
			if (this->values[i][j] == '0')
			{
				this->Squares[index].setSquareFillColor(sf::Color::Red);
			}
			index++;
		}
	}
}

void Solver::updateValues(Board& board)
{
	//auto front = solvedList.end();
	//std::advance(front, -order);
	Node* temp = solved[order];
	temp->copyToAnotherArray(this->values);
}

void Solver::getVal(char values[][3])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			this->values[i][j] = values[i][j];
		}
	}
}

void Solver::changeOrder(char z)
{
	switch (z)
	{
	case 'b':
		if (this->order + 1 < this->solved.size())
		{
			this->order += 1;
		}
		break;
	case 'n':
		if (this->order - 1 >= 0)
		{
			this->order -= 1;
		}
		break;
	}
}

void Solver::createSolverBoard(sf::Font& Font)
{
	int index = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			this->Squares[index].setValue(this->values[i][j]);

			this->Squares[index].setSquarePosition(sf::Vector2f(335 + j * (40+5), 600+i*(40+5)));
			this->Squares[index].setSquareFillColor(sf::Color::Blue);
			this->Squares[index].setSquareSize(sf::Vector2f(40, 40));
			if (this->Squares[index].getValue() == '0')
			{
				this->Squares[index].setSquareFillColor(sf::Color::Red);
			}

			this->Squares[index].setSquareTextString(std::to_string(this->Squares[index].getValue()));
			this->Squares[index].setSquareTextFont(Font);
			
			this->TextInsideSquares[index].setFillColor(sf::Color::White);
			this->TextInsideSquares[index].setStyle(sf::Text::Bold);
			this->TextInsideSquares[index].setCharacterSize(20);
			this->TextInsideSquares[index].setFont(Font);
			this->TextInsideSquares[index].setPosition(sf::Vector2f(335 + j * (40 + 5), 600 + i * (40 + 5)));
			this->TextInsideSquares[index].setString(std::to_string(this->Squares[index].getValue()-48));
			//std::cout << std::to_string(this->Squares[index].getValue() - 48) << "\n";

			index++;
		}
	}
}

void createChildren(Node* node, std::list<Node*> &open, std::list<Node*> &closed)
{
	std::vector<char> moves;
	sf::Vector2i zero = node->getZero();

	if (zero.y - 1 >= 0)
	{
		moves.push_back('d');
	}
	if (zero.y + 1 <= 2)
	{
		moves.push_back('u');
	}
	if (zero.x + 1 <= 2)
	{
		moves.push_back('l');
	}
	if (zero.x - 1 >= 0)
	{
		moves.push_back('r');
	}

	for (int i = 0; i < moves.size(); i++)
	{
		//std::cout << " = " << moves.size() << "\n";
		Node* temp = new Node;
		temp->copy(node->getArray());
		temp->updateZeroPosition();
		switch (moves[i])
		{
		case 'd':
			temp->moveOnBoard(moves[i]);
			temp->setMove(moves[i]);
			break;
		case 'u':
			temp->moveOnBoard(moves[i]);
			temp->setMove(moves[i]);
			break;
		case 'r':
			temp->moveOnBoard(moves[i]);
			temp->setMove(moves[i]);
			break;
		case 'l':
			temp->moveOnBoard(moves[i]);
			temp->setMove(moves[i]);
			break;
		}

		if (processNode(open, temp->getValueBoard()) && processNode(closed, temp->getValueBoard()))
		{
			delete temp;
		}
		else
		{
			temp->manhattanDistance();
			temp->setG(node->getG() + 1);
			temp->setF();
			temp->setParent(node);
			open.push_back(temp);

		}
	}
}

bool compareArrays(const char arr1[3][3], const char arr2[3][3]) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (arr1[i][j] != arr2[i][j])
				return false;
		}
	}
	return true;
}

bool processNode(std::list<Node*>& nodeList, const char targetData[3][3]) {
	for (auto it = nodeList.begin(); it != nodeList.end(); ++it) {
		if (compareArrays((*it)->getValueBoard(), targetData)) {
			return true;
		}
	}
	return false;
}

void sortList(std::list<Node*>& nodeList)
{
	nodeList.sort([](Node* a, Node* b)
		{
			return a->getF() < b->getF();
		});
}