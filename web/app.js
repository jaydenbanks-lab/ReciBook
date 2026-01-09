async function loadRecipes() {
  const res = await fetch("/api/recipes");
  const recipes = await res.json();

  const list = document.getElementById("recipe-list");
  list.innerHTML = "";

  recipes.forEach((r) => {
    const item = document.createElement("div");
    item.className = "item";
    item.textContent = `${r.title} (${r.calories} cal)`;
    item.onclick = () => showRecipe(r);
    list.appendChild(item);
  });
}

function showRecipe(r) {
  const details = document.getElementById("recipe-details");
  details.textContent = JSON.stringify(r, null, 2);
}

async function addRecipeFromForm() {
  const title = document.getElementById("title").value.trim();
  const calories = parseInt(document.getElementById("calories").value || "0", 10);
  const rating = parseInt(document.getElementById("rating").value || "0", 10);

  const ingredients = document
    .getElementById("ingredients")
    .value.split("\n")
    .map(s => s.trim())
    .filter(Boolean);

  const steps = document
    .getElementById("steps")
    .value.split("\n")
    .map(s => s.trim())
    .filter(Boolean);

  if (!title) {
    alert("Title is required.");
    return;
  }

  const body = { title, calories, rating, ingredients, steps };

  const res = await fetch("/api/recipes", {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(body)
  });

  if (!res.ok) {
    const msg = await res.text();
    alert("Failed to add recipe: " + msg);
    return;
  }

  // Clear form
  document.getElementById("title").value = "";
  document.getElementById("calories").value = "";
  document.getElementById("rating").value = "";
  document.getElementById("ingredients").value = "";
  document.getElementById("steps").value = "";

  await loadRecipes();
}

document.getElementById("add-btn").addEventListener("click", addRecipeFromForm);

// Load recipes when the page opens
loadRecipes();
