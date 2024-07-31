#pragma once

#include <string>
#include <memory>
#include <filesystem>
#include <unordered_map>
#include <SDL2/SDL_image.h>

namespace fs = std::filesystem;

class TextureManager
{
public:

    static std::shared_ptr<TextureManager> getManager();

    const SDL_Texture* getTexture(const std::string&) const;

private:

    TextureManager();

    TextureManager(const TextureManager&) = delete;

    TextureManager(TextureManager&&) noexcept = delete;

    TextureManager& operator=(const TextureManager&) = delete;

    TextureManager& operator=(TextureManager&&) noexcept = delete;

    void loadAllTexturesFromDirectory(const std::string&);

private:

    static std::shared_ptr<TextureManager> manager_;

    std::string prefix_;

    mutable std::unordered_map<std::string, SDL_Texture> textures_;
};