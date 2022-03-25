#pragma once

class CharacterRow : public std::enable_shared_from_this<CharacterRow>
{
public:
	int Index;
	std::string Id;
	std::string Pw;
};

// Ό³Έν :
class CharacterTable
{
public:
	// constrcuter destructer
	CharacterTable();
	~CharacterTable();

	// delete Function
	CharacterTable(const CharacterTable& _Other) = delete;
	CharacterTable(CharacterTable&& _Other) noexcept = delete;
	CharacterTable& operator=(const CharacterTable& _Other) = delete;
	CharacterTable& operator=(CharacterTable&& _Other) noexcept = delete;

protected:
	// std::vector<>

private:

};

