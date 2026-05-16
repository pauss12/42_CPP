void foundItem(int index, int value)
{
    std::cout << "✅ ¡Encontrado! El valor " << value << " está en la posición: " << index << std::endl;
}

template <typename T>
void easyfind(const T &container, int value)
{
    typename T::const_iterator it;
    int index;

    if (container.empty())
        throw NotFoundException();
    it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw NotFoundException();
    else
    {
        index = std::distance(container.begin(), it);
        foundItem(index, value);
    }
}

const char *NotFoundException::what() const throw()
{
    return "❌ ERROR: Valor no encontrado en el contenedor 🔍";
}