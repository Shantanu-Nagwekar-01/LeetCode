class Solution:
    def findAllRecipes(
        self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]
    ) -> List[str]:
        res = []
        indegree = {}
        graph = {}

        for i, recipe in enumerate(recipes):
            indegree[recipe] = len(ingredients[i])
            for ingredient in ingredients[i]:
                if ingredient not in graph:
                    graph[ingredient] = []
                graph[ingredient].append(recipe)

        queue = deque(supplies)
        available = set(supplies)

        while queue:
            ingredient = queue.popleft()
            if ingredient in graph:
                for recipe in graph[ingredient]:
                    indegree[recipe] -= 1
                    if indegree[recipe] == 0:
                        res.append(recipe)
                        queue.append(recipe)
                        available.add(recipe)        

        return res
