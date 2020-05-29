
##
# Class: Country class. Each country has a name, population, area, and a continent it belongs to.
#
class Country:
    ##
    # Constructor
    #@param - name (name of Country)
    #@param - pop (population of Country)
    #@param - area (area of Country)
    #@param - continent (continent of Country)
    def __init__(self, name, pop, area, continent) :
        self._name=name #name of a country
        self._pop=pop #population of a country
        self._area=area #area of country
        self._continent=continent #continent of country
    ##
    # Convert to string a Country
    #
    def __repr__(self):
        return self._name + " in " + self._continent

    ##
    # sets the population of a country
    #@param - pop (a new population)
    #
    def setPopulation(self, pop):
        self._pop = pop
    ##
    # gets the name of the country
    #
    def getName(self):
        return self._name
    ##
    # gets the area of the country
    #
    def getArea(self):
        return self._area
    ##
    # gets the population of a country
    #
    def getPopulation(self):
        return self._pop
    ##
    # gets the continent of a country
    #
    def getContinent(self):
        return self._continent
    ##
    # computes the population density (pop/area) and returns this value.
    #
    def getPopDensity(self):
        return self._pop/self._area

    ##
    # given another country,
    #