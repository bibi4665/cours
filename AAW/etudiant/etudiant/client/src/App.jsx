import { useEffect, useState } from "react";

const GENRES = ["roman", "science-fiction", "policier", "essai"];

export default function App() {
    // TODO : états (liste, filtre, livre sélectionné, champs du formulaire, erreurs)
    const [livres, setLivres] = useState([]);
    const [filtre, setFiltre] = useState("");
    const [livreSelectionne, setLivreSelectionne] = useState(undefined);

    // TODO : fonction qui recharge la liste (GET /api/livres, avec ?genre= si un filtre est choisi)
    const chargerLivres = () =>{
        const genreFiltre = `?genre=${filtre}`
        fetch(`/api/livres${genreFiltre}`)
            .then(res =>{
                if (res.status === 200){
                    return res.json();
                }
            })
            .then((ls)=>{
                setLivres(ls);
            });
    }

    useEffect(() => {
        // TODO : charger la liste au démarrage et quand le filtre change
        chargerLivres();
    }, [filtre]);

    // TODO : fonctions pour ajouter, changer l'état de lecture, supprimer, afficher le détail
    const selectionner = (id)=>{
    fetch(`/api/livres/${id}`)
        .then()
        .then()}
}

    return (
        <div style={{ padding: "2rem", maxWidth: 700 }}>
            <h1>Bibliothèque</h1>

            <label>
                Genre
                <select onChange={e => setFiltre(e.currentTarget.value)}>
                    <option>
                        {
                            ["roman", "science-fiction", "policier", "essai"].map(g=><option key={g} value={g}>)
                        }
                    </option>
                </select>
            </label>

            <div>
                <ul>
                    {
                        livres && livres.map(l=>{
                            return <li key={{l.id} onClick{}}>
                                <span>{l.titre}</span>
                                <span>{l.auteur}</span>
                                <span>{l.lu? "lu" : "non lu"}</span>
                            </li>
                        })
                    }
                </ul>
            </div>


            {
                // TODO : formulaire, filtre, liste, encadré de détail
            }
        </div>
    );
}
