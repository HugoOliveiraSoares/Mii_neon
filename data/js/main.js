window.addEventListener("DOMContentLoaded", (event) => {
  adjustTabs();
  colorPickInit();
  getBright();
  fetchEffects();
});

function colorPickInit() {

  var _width = 0;

  if(window.innerHeight <= 750) {
    _width = 220;
  } else{
    _width = 300;
  }

  const colorPicker = new iro.ColorPicker("#colorPicker", {
    width: _width,
    color: "#ffffff", // TODO: Colocar a ultima cor usada, getColor() do esp32
    borderWidth: 2,
    borderColor: "var(---my-border-color)",
    layout: [
      {
        component: iro.ui.Wheel,
        options: {
          wheelLightness: false,
        },
      },
      {
        component: iro.ui.Slider,
        options: {
          sliderType: "saturation",
          borderColor: "var(---my-border-color)",
        },
      },
      {
        component: iro.ui.Slider,
        options: {
          sliderType: "value",
          borderColor: "var(---my-border-color)",
        },
      },
    ],
  });

  colorPicker.on("color:change", function (color) {
    const _color = {
      rgb: {
        r: color.red,
        g: color.green,
        b: color.blue,
      },
    };
    setColor(_color);
  });
}

function adjustTabs() {
  const tabs = document.getElementById("bottomNavBar");
  const colors = document.getElementById("colors");
  const effects = document.getElementById("effects");
  if (window.innerHeight >= 800 && window.innerWidth >= 600) {
    tabs.style.display = "none";
    colors.classList.add("show");
    colors.classList.add("active");
    effects.classList.add("show");
    effects.classList.add("active");
  } else {
    tabs.style.display = "flex";
    effects.classList.remove("show");
    effects.classList.remove("active");
  }
}

function selectEffect(effectName) {
  console.log("Efeito selecionado:", effectName);
  const _effect = {
    effect: effectName,
  };
  setEffects(_effect);
}

function getBright() {
  document.getElementById("brightInput").addEventListener("input", function () {
    const _bright = {
      bright: this.value,
    };
    setBright(_bright);
  });
}

function setColor(color) {
  console.log(color);
  const options = {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify(color),
  };

  fetch("/setColor", options)
    .then((data) => {
      if (!data.ok) {
        throw Error(data.status);
      }
      return data.json();
    })
    .then((response) => {
      console.log(response);
    })
    .catch((e) => {
      console.log(e);
    });
}

function setBright(bright) {
  console.log(bright);
  const options = {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify(bright),
  };

  fetch("/setBright", options)
    .then((data) => {
      if (!data.ok) {
        throw Error(data.status);
      }
      return data.json();
    })
    .then((response) => {
      console.log(response);
    })
    .catch((e) => {
      console.log(e);
    });
}

function fetchEffects() {
  fetch("/effects")
    .then((response) => response.json())
    .then((data) => {
      if (data.effects && Array.isArray(data.effects)) {
        createEffectButtons(data.effects);
      }
    })
    .catch((error) => console.error("Erro ao buscar efeitos:", error));
}

function createEffectButtons(effects) {
  const container = document.getElementById("effects-container");

  if (!container) {
    console.error("Elemento #effects-container não encontrado.");
    return;
  }

  container.innerHTML = ""; // Limpa antes de adicionar os novos botões

  effects.forEach((effect) => {
    const button = document.createElement("li");
    button.className = "btn btn-secondary w-100 my-2";
    button.textContent = effect;
    button.onclick = () => selectEffect(effect);

    container.appendChild(button);
  });
}

function setEffects(effect) {
  const options = {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify(effect),
  };

  fetch("/effects", options)
    .then((data) => {
      if (!data.ok) {
        throw Error(data.status);
      }
      return data.json();
    })
    .then((response) => {
      console.log(response);
    })
    .catch((e) => {
      console.log(e);
    });
}
