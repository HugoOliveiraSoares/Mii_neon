window.addEventListener("DOMContentLoaded", (event) => {
    adjustTabs();
    colorPickInit();
    getBright();
});

function colorPickInit() {
    const colorPicker = new iro.ColorPicker("#colorPicker", {
        width: 300,
        color: "#ffffff", // TODO: Colocar a ultima cor usada, getColor() do esp32
        borderWidth: 2,
        borderColor: "#ffffff",
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
                },
            },
            {
                component: iro.ui.Slider,
                options: {
                    sliderType: "value",
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
}

function getBright() {
    document.getElementById("brightInput").addEventListener(
        "input",
        function () {
            const _bright = {
                bright: this.value,
            };
            setBright(_bright);
        },
    );
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
